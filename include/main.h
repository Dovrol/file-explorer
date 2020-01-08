//
// Created by Wiktor Kubis on 08/01/2020.
//
#include <gtk/gtk.h>

#ifndef EKSPLORATOR_MAIN_H
#define EKSPLORATOR_MAIN_H

GtkWidget *window;
GtkWidget *fixed1;
GtkWidget *view1;
GtkTreeStore *treeStore;
GtkTreeView *tv1;
GtkTreeViewColumn *cx1;
GtkTreeViewColumn *cx2;
GtkTreeViewColumn *cx3;
GtkTreeViewColumn *cx4;
GtkTreeSelection *selection;
GtkCellRenderer *cr1;
GtkCellRenderer *cr2;
GtkCellRenderer *cr3;
GtkCellRenderer *cr4;
GtkCellRenderer *pixbuf;
GtkToolbar *toolbar1;
GtkBuilder *builder;
GError *error;
GdkPixbuf *folderIcon;
GdkPixbuf *fileIcon;
GdkPixbuf *homeIcon;
GtkLabel *pathDisplayer;

#define ROOT "/"
#define SLASH "/"



#endif //EKSPLORATOR_MAIN_H
