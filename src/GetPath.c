//
// Created by Wiktor Kubis on 08/01/2020.
//
#include "Functions.h"
#include "main.h"


// RECURRENT FUNCTION THAT IS GETTING PATH OF FILE
char *get_path(GtkTreeModel *model, GtkTreeIter iter, char *path) {
	GtkTreeIter parent_iter;
	char *value;
	if (gtk_tree_model_iter_parent(model, &parent_iter, &iter) == FALSE) {
		gtk_tree_model_get(model, &iter, 0, &value, -1);
		sprintf(path, "%s", value);
		return path;
	} else {
		gtk_tree_model_get(model, &iter, 0, &value, -1);
		sprintf(path, "%s%s%s", get_path(model, parent_iter, path), SLASH, value);
		return path;
	}
}