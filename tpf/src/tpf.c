#include <gtk/gtk.h>
#include <stdlib.h>
#include <time.h>

#include"declaracionesgtk.h"
#include <gtk/gtk.h>

 int main (int argc, char *argv[])
 {
	//Para el GtkBuilder
    guint ret;
    GtkBuilder *builder;
    GError *error = NULL;

    gtk_init (&argc, &argv);

    builder = gtk_builder_new();
	//Se carga el builder
	ret = gtk_builder_add_from_file(builder, "SuffragetteGtk.glade", &error);
	if (ret == 0) {
		g_print("Error en la función gtk_builder_add_from_file:\n%s", error->message);
		return 1;
	}

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window")); //ventanaprincipal
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    window2 = GTK_WIDGET(gtk_builder_get_object(builder, "window2"));
    g_signal_connect (window2, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    window3 = GTK_WIDGET(gtk_builder_get_object(builder, "window3"));
    g_signal_connect (window3, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    window4 = GTK_WIDGET(gtk_builder_get_object(builder, "window4"));
    g_signal_connect (window4, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    window6 = GTK_WIDGET(gtk_builder_get_object(builder, "window6"));

    botonminfo = GTK_WIDGET(gtk_builder_get_object(builder, "botonminfo")); //boton para abrir ventana de config
    g_signal_connect(botonminfo, "clicked", G_CALLBACK (botonminfo_clicked_cb), NULL);

    botonatras = GTK_WIDGET(gtk_builder_get_object(builder, "botonatras"));
    g_signal_connect(botonatras, "clicked", G_CALLBACK (botonatras_clicked_cb), NULL);

    botonatras2 = GTK_WIDGET(gtk_builder_get_object(builder, "botonatras2"));
    g_signal_connect(botonatras2, "clicked", G_CALLBACK (botonatras2_clicked_cb), NULL);

    botonreglas = GTK_WIDGET(gtk_builder_get_object(builder, "botonreglas"));
    g_signal_connect(botonreglas, "clicked", G_CALLBACK (botonreglas_clicked_cb), NULL);

    botoncontinuar = GTK_WIDGET(gtk_builder_get_object(builder, "botoncontinuar"));
    g_signal_connect(botoncontinuar, "clicked", G_CALLBACK (botoncontinuar_clicked_cb), NULL);

    policia = GTK_WIDGET(gtk_builder_get_object(builder, "policia"));
    g_signal_connect (policia, "clicked", G_CALLBACK (pol_clicked_cb), NULL);

    cantidad_t = GTK_WIDGET(gtk_builder_get_object(builder, "cantidad_t"));

    suffragette = GTK_WIDGET(gtk_builder_get_object(builder, "suffragette"));
    g_signal_connect (suffragette, "clicked", G_CALLBACK (suff_clicked_cb), NULL);

    aleatorio = GTK_WIDGET(gtk_builder_get_object(builder, "aleatorio"));
    g_signal_connect (aleatorio, "clicked", G_CALLBACK (ale_clicked_cb), NULL);

    lideres = GTK_WIDGET(gtk_builder_get_object(builder, "lideres"));
    g_signal_connect (lideres, "clicked", G_CALLBACK (suffs_clicked_cb), NULL);

    inspectores = GTK_WIDGET(gtk_builder_get_object(builder, "inspectores"));
    g_signal_connect (inspectores, "clicked", G_CALLBACK (pols_clicked_cb), NULL);

    jugador = GTK_WIDGET(gtk_builder_get_object(builder, "jugador"));
    g_signal_connect (jugador, "clicked", G_CALLBACK (jugador_clicked_cb), NULL);

    computadora = GTK_WIDGET(gtk_builder_get_object(builder, "computadora"));
    g_signal_connect (computadora, "clicked", G_CALLBACK (computadora_clicked_cb), NULL);

    botonaplicar = GTK_WIDGET(gtk_builder_get_object(builder, "botonaplicar"));
    g_signal_connect(botonaplicar, "clicked", G_CALLBACK (botonaplicar_clicked_cb), NULL);

	//Ventana principal
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

	//Box donde estara el Tablero
	box_tablero = GTK_WIDGET(gtk_builder_get_object(builder, "box_tablero"));

	//Labels
	label_turno = GTK_WIDGET(gtk_builder_get_object(builder, "label_turno"));
	label_estado = GTK_WIDGET(gtk_builder_get_object(builder, "label_estado"));

	gtk_box_pack_start(GTK_BOX(box_tablero), crear_tablero(), TRUE, FALSE, 20);

    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

    gtk_widget_show_all (window);

    gtk_main ();

    return 0;
 }
