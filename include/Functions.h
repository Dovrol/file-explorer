//
// Created by Wiktor Kubis on 08/01/2020.
//

#ifndef EKSPLORATOR_FUNCTIONS_H
#define EKSPLORATOR_FUNCTIONS_H
#include <gtk/gtk.h>

// Function that sets lastModified to date of last modification of file and size to it's size
void fileInfo(char *f, char *lastModified, char *size);

// Function that make file tree with depth of 2
void makeTree(GtkTreeModel *model, char *path, GtkTreeIter topLevel, int counter);

// RECURRENT FUNCTION THAT IS GETTING PATH OF FILE
char *get_path(GtkTreeModel *model, GtkTreeIter iter, char *path);

// FUNCTION THAT IS ACTIVATED WHEN TREE ELEMENT IS CLICKED
void on_select_changed(GtkTreeSelection *b);

// FUNCTION THAT IS ACTIVATED WHEN EXPANDER IS ACTIVATED
void on_tv1_row_expanded(GtkTreeView *tree_view, GtkTreeIter *iter, GtkTreePath *path);

#endif //EKSPLORATOR_FUNCTIONS_H
