//
// Created by Wiktor Kubis on 08/01/2020.
//
#include <gtk/gtk.h>
#include "Functions.h"
#include "main.h"


void makeTree(GtkTreeModel *model, char *path, GtkTreeIter topLevel, int counter) {
	GtkTreeIter child;
	DIR *dp;
	struct dirent *ep;

//	Depth counter
	if (counter <= 0) {
		return;
	}

//	Check if dir exist
	dp = opendir(path);
	if (dp == NULL) {
		return;
	}


	if (gtk_tree_model_iter_children(model, &child, &topLevel)) {
		while (TRUE) {
			if (!gtk_tree_store_remove(treeStore, &child)) {
				break;
			}
		}
	}

	ep = readdir(dp);
	counter--;

	while (ep != NULL) {

		// Skip "." and ".."
		if (strcmp(ep->d_name, ".") == 0 || strcmp(ep->d_name, "..") == 0) {
			ep = readdir(dp);
			continue;
		}

		// Saving size and last modified date of file
		char filePath[1024];
		sprintf(filePath, "%s%s%s", path, SLASH, ep->d_name);
		char *lastModified = malloc(1024);
		char *size = malloc(1024);
		fileInfo(filePath, lastModified, size);

		// Setting columns
		gtk_tree_store_append(treeStore, &child, &topLevel);

		// Column 0 -> Name of file
		gtk_tree_store_set(treeStore, &child, 0, ep->d_name, -1);

		// Column 1 -> Kind (Folder or file )
		// Column 3 -> Icon
		// Column 4 -> Size
		if (ep->d_type == DT_DIR) {
			gtk_tree_store_set(treeStore, &child, 1, "Folder", -1);
			gtk_tree_store_set(treeStore, &child, 3, folderIcon, -1);
			gtk_tree_store_set(treeStore, &child, 4, "--", -1);

		} else {
			gtk_tree_store_set(treeStore, &child, 1, "File", -1);
			gtk_tree_store_set(treeStore, &child, 3, fileIcon, -1);
			gtk_tree_store_set(treeStore, &child, 4, size, -1);
		}
		// Column 2 -> Last modified
		gtk_tree_store_set(treeStore, &child, 2, lastModified, -1);
		free(lastModified);
		free(size);

		// Calling makeTree with new path and counter decremented by 1
		char newPath[1024];
		sprintf(newPath, "%s%s%s", path, SLASH, ep->d_name);
		makeTree(model, newPath, child, counter);

		ep = readdir(dp);
	}
	closedir(dp);
}