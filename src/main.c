//
// Created by Wiktor Kubis on 02/01/2020.
//
#include <stdlib.h>
#include "main.h"
#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);

	// Setting window made in Glade

	builder = gtk_builder_new_from_file("tree.glade");
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_builder_connect_signals(builder, NULL);

	fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
	view1 = GTK_WIDGET(gtk_builder_get_object(builder, "view1"));
	treeStore = GTK_TREE_STORE(gtk_builder_get_object(builder, "treeStore"));
	tv1 = GTK_TREE_VIEW(gtk_builder_get_object(builder, "tv1"));
	cx1 = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx1"));
	cx2 = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx2"));
	cx3 = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx3"));
	cx4 = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx4"));
	cr1 = GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr1"));
	cr2 = GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr2"));
	cr3 = GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr3"));
	cr4 = GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr4"));
	pixbuf = GTK_CELL_RENDERER(gtk_builder_get_object(builder, "pixbuf"));
	selection = GTK_TREE_SELECTION(gtk_builder_get_object(builder, "select"));
	toolbar1 = GTK_TOOLBAR(gtk_builder_get_object(builder, "toolbar1"));
	pathDisplayer = GTK_LABEL(gtk_builder_get_object(builder, "pathDisplayer"));


	gtk_tree_view_column_add_attribute(cx1, cr1, "text", 0);
	gtk_tree_view_column_add_attribute(cx2, cr2, "text", 1);
	gtk_tree_view_column_add_attribute(cx3, cr3, "text", 2);
	gtk_tree_view_column_add_attribute(cx1, pixbuf, "pixbuf", 3);
	gtk_tree_view_column_add_attribute(cx4, cr4, "text", 4);
	gtk_cell_renderer_set_alignment(cr3, 0.90, 0);
	gtk_cell_renderer_set_alignment(cr4, 0.90, 0);
	gtk_cell_renderer_set_alignment(cr2, 0.1, 0);
	g_object_set(cr1, "font", "Arial 12", NULL);
	g_object_set(cr2, "font", "Arial 12", NULL);
	g_object_set(cr3, "font", "Arial 12", NULL);



	GtkTreeIter iter;

	//Creating starting tree
	gtk_tree_store_append(treeStore, &iter, NULL);
	gtk_tree_store_set(treeStore, &iter, 0, ROOT, -1);
	gtk_tree_store_set(treeStore, &iter, 1, "ROOT", -1);
//	gtk_tree_store_set(treeStore, &iter, 2, fileInfo(ROOT), -1);


	// ICONS
	folderIcon = gtk_icon_theme_load_icon (gtk_icon_theme_get_default(), "folder", 20, 0, &error);
	fileIcon = gtk_icon_theme_load_icon (gtk_icon_theme_get_default(), "emblem-documents", 20, 0, &error);
	homeIcon = gtk_icon_theme_load_icon (gtk_icon_theme_get_default(), "user-home", 20, 0, &error);
	gtk_tree_store_set(treeStore, &iter, 3, homeIcon, -1);


	// MAIN LOOP
	gtk_widget_show(window);
	gtk_main();
	return EXIT_SUCCESS;
}