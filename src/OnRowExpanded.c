//
// Created by Wiktor Kubis on 08/01/2020.
//
#include "Functions.h"

// FUNCTION THAT IS ACTIVATED WHEN EXPANDER IS ACTIVATED
void on_tv1_row_expanded(GtkTreeView *tree_view, GtkTreeIter *iter, GtkTreePath *path) {

	GtkTreeSelection *selections;
	selections = gtk_tree_view_get_selection(tree_view);
	gtk_tree_selection_select_path(selections, path);
}