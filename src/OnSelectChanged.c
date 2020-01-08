//
// Created by Wiktor Kubis on 08/01/2020.
//

#include "Functions.h"
#include "main.h"

// FUNCTION THAT IS ACTIVATED WHEN TREE ELEMENT IS CLICKED
void on_select_changed(GtkTreeSelection *b) {
	GtkTreeIter iter;
	GtkTreeModel *model;

	if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(b), &model, &iter) == FALSE) {
		return;
	}
	char *path = malloc(1024);
	path = get_path(model, iter, path);


	// DISPLAYING PATH ON BOTTOM
	char pathLabel[1024];
	path++;
	sprintf(pathLabel, "PATH: %s", path);
	path--;
	gtk_label_set_text(pathDisplayer, pathLabel);

	// MAKING TREE
	makeTree(model, path, iter, 2);
	free(path);
}