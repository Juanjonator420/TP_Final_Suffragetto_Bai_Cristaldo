#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include"declaraciones.h"
#include"declaracionesgtk.h"

#include<gtk/gtk.h>

//Un vector de Strings, almacena ubicacion de imagenes
char *imagenest[] = {"./IMG/casillas/albert-hall.jpg",
					"./IMG/casillas/House-of-commons.jpg",
					"./IMG/casillas/hospital-vacio.jpg",
					"./IMG/casillas/carcel-vacia.jpg",
					"./IMG/casillas/on-arena.jpg",
					"./IMG/casillas/no-arena.jpg"};

char *imagenesp[] = {"./IMG/policias/inpsector_herido.jpg",
					 "./IMG/policias/inpsector-on_arena.jpg",
					 "./IMG/policias/inspector_albert-hall.jpg",
					 "./IMG/policias/inspector_-off_arena.jpg",
					 "./IMG/policias/policia-albert-hall.jpg",
					 "./IMG/policias/policia-herido.jpg",
					 "./IMG/policias/policia-off_arena.jpg",
					 "./IMG/policias/policia-on_arena.jpg"};

char *imagenesf[] = {"./IMG/suffragettes/lider-arrestado.jpg",
					 "./IMG/suffragettes/lider-house_of_commons.jpg",
					 "./IMG/suffragettes/lider-off_arena.jpg",
					 "./IMG/suffragettes/lider-on_arena.jpg",
					 "./IMG/suffragettes/suffr-arrestado.jpg",
					 "./IMG/suffragettes/suffr-house_of_commons.jpg",
					 "./IMG/suffragettes/suffr-off_arena.jpg",
					 "./IMG/suffragettes/suffr-on_arena.jpg"};

void botonminfo_clicked_cb(GtkWidget *widget, gpointer data) {

	gtk_widget_show_all(window2);
	gtk_widget_hide(window);
}
void botonatras_clicked_cb(GtkWidget *widget, gpointer data) {

	gtk_widget_hide(window2);
	gtk_widget_show_all(window);
}
void botonreglas_clicked_cb(GtkWidget *widget, gpointer data) {

	gtk_widget_show_all(window3);
}
void botonatras2_clicked_cb(GtkWidget *widget, gpointer data) {

	gtk_widget_hide(window3);
	gtk_widget_show_all(window);
}

void botoncontinuar_clicked_cb(GtkWidget *widget, gpointer data) {

	gtk_widget_show_all(window4);
	gtk_widget_hide(window);
}

void botonsalir_clicked_cb(GtkWidget *widget, gpointer data) {

	gtk_main_quit();
}

void pol_clicked_cb(GtkWidget *widget, gpointer data)  {

	limite_de_turno=1;
	g_print("Se juega con:%d",limite_de_turno);
}

void suff_clicked_cb(GtkWidget *widget, gpointer data)  {

	limite_de_turno=2;
	g_print("Se juega con es:%d",limite_de_turno);
}

void ale_clicked_cb(GtkWidget *widget, gpointer data)  {

	color=1;
	g_print("El color es:%d",color);
}

void suffs_clicked_cb(GtkWidget *widget, gpointer data)  {

	color=2;
	g_print("El color es:%d",color);
}

void pols_clicked_cb(GtkWidget *widget, gpointer data)  {

	srand(time(NULL));
	color=rand()%2+1;
	g_print("El color es:%d",color);
}

void jugador_clicked_cb(GtkWidget *widget, gpointer data)  {

}

void computadora_clicked_cb(GtkWidget *widget, gpointer data)  {

}

void botonaplicar_clicked_cb(GtkWidget *widget, gpointer data) {

	gtk_widget_hide(window4);
	gtk_widget_show_all(window6);

}

void tablero_cb(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	guint i,j;
	i = (GUINT_FROM_LE(event->y) / 35); //las imagenes tienen son 50x50pixeles
	j = (GUINT_FROM_LE(event->x) / 35);
	gchar *temp = g_strdup_printf("Presiono la imagen coordenada [%d,%d]", i,j);

	gtk_label_set_text(GTK_LABEL(label_estado), temp);

	int dado = rand() % 6;
	temp = g_strdup_printf("Tiramos el dado y obtenemos: %d", dado + 1);
	gtk_label_set_text(GTK_LABEL(label_turno), temp);

	g_free(temp);

}

GtkWidget *crear_tablero(){
	int i, j;
	GtkWidget *imagen; //auxiliar para cargar la imagen
	GtkWidget *eventbox;
	eventbox = gtk_event_box_new();
	tablero = gtk_grid_new();

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 2; j++){
			imagen = gtk_image_new_from_file(imagenest[(2)]);
			gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 4; i < 10; i++) {
		for (j = 0; j < 1; j++){
			imagen = gtk_image_new_from_file(imagenest[(2)]);
			gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 10; i < 17; i++) {
		for (j = 0; j < 2; j++){
			imagen = gtk_image_new_from_file(imagenest[(2)]);
			gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 0; i < 5; i++) {
		for (j = 2; j < 4; j++) {
				imagen = gtk_image_new_from_file(imagenest[5]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 4; i < 10; i++) {
		for (j = 1; j < 2; j++) {
				imagen = gtk_image_new_from_file(imagenest[5]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 6; i < 11; i++) {
		for (j = 2; j < 4; j++) {
				imagen = gtk_image_new_from_file(imagenest[5]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 12; i < 17; i++) {
		for (j = 2; j < 4; j++) {
				imagen = gtk_image_new_from_file(imagenest[5]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 0; i < 3; i++) {
		for (j = 4; j < 13; j++) {
				imagen = gtk_image_new_from_file(imagenest[4]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 3; i < 5; i++) {
		for (j = 7; j < 10; j++) {
				imagen = gtk_image_new_from_file(imagenest[0]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 3; i < 4; i++) {
		for (j = 4; j < 7; j++) {
			if(j!=6){
				imagen = gtk_image_new_from_file(imagenest[4]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}else{
				imagen = gtk_image_new_from_file(imagenesf[7]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}
		}
	}

	for (i = 4; i < 5; i++) {
		for (j = 4; j < 7; j++) {
			if(j!=4){
				imagen = gtk_image_new_from_file(imagenesf[7]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}else{
				imagen = gtk_image_new_from_file(imagenesf[3]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}
		}
	}

	for (i = 3; i < 4; i++) {
		for (j = 10; j < 13; j++) {
			if(j!=10){
				imagen = gtk_image_new_from_file(imagenest[4]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}else{
				imagen = gtk_image_new_from_file(imagenesf[7]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}
		}
	}

	for (i = 4; i < 5; i++) {
		for (j = 10; j < 13; j++) {
			if(j!=12){
				imagen = gtk_image_new_from_file(imagenesf[7]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}else{
				imagen = gtk_image_new_from_file(imagenesf[3]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}
		}
	}

	for (i = 5; i < 6; i++) {
		for (j = 4; j < 13; j++) {
			if(j!=8){
				imagen = gtk_image_new_from_file(imagenesf[7]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}else{
				imagen = gtk_image_new_from_file(imagenesf[3]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}
		}
	}

	for (i = 5; i < 6; i++) {
		for (j = 2; j < 4; j++) {
			if(j!=2){
				imagen = gtk_image_new_from_file(imagenesf[6]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}else{
				imagen = gtk_image_new_from_file(imagenesf[2]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}
		}
	}

	for (i = 5; i < 6; i++) {
		for (j = 13; j < 15; j++) {
			if(j!=14){
				imagen = gtk_image_new_from_file(imagenesf[6]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}else{
				imagen = gtk_image_new_from_file(imagenesf[2]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}
		}
	}

	for (i = 11; i < 12; i++) {
		for (j = 4; j < 13; j++) {
			if(j!=8){
				imagen = gtk_image_new_from_file(imagenesp[7]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}else{
				imagen = gtk_image_new_from_file(imagenesp[1]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}
		}
	}

	for (i = 12; i < 13; i++) {
		for (j = 4; j < 7; j++) {
			if(j!=4){
				imagen = gtk_image_new_from_file(imagenesp[7]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}else{
				imagen = gtk_image_new_from_file(imagenesp[1]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}
		}
	}

	for (i = 13; i < 14; i++) {
		for (j = 4; j < 7; j++) {
			if(j!=6){
				imagen = gtk_image_new_from_file(imagenest[4]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}else{
				imagen = gtk_image_new_from_file(imagenesp[7]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}
		}
	}

	for (i = 12; i < 13; i++) {
		for (j = 10; j < 13; j++) {
			if(j!=12){
				imagen = gtk_image_new_from_file(imagenesp[7]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}else{
				imagen = gtk_image_new_from_file(imagenesp[1]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}
		}
	}

	for (i = 11; i < 12; i++) {
		for (j = 2; j < 4; j++) {
			if(j!=2){
				imagen = gtk_image_new_from_file(imagenesp[6]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}else{
				imagen = gtk_image_new_from_file(imagenesp[3]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}
		}
	}

	for (i = 11; i < 12; i++) {
		for (j = 13; j < 15; j++) {
			if(j!=14){
				imagen = gtk_image_new_from_file(imagenesp[6]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}else{
				imagen = gtk_image_new_from_file(imagenesp[3]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}
		}
	}

	for (i = 13; i < 14; i++) {
		for (j = 10; j < 13; j++) {
			if(j!=10){
				imagen = gtk_image_new_from_file(imagenest[4]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}else{
				imagen = gtk_image_new_from_file(imagenesp[7]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			}
		}
	}

	for (i = 6; i < 11; i++) {
		for (j = 4; j < 13; j++) {
				imagen = gtk_image_new_from_file(imagenest[4]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 12; i < 14; i++) {
		for (j = 7; j < 10; j++) {
				imagen = gtk_image_new_from_file(imagenest[1]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 14; i < 17; i++) {
		for (j = 4; j < 13; j++) {
				imagen = gtk_image_new_from_file(imagenest[4]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 0; i < 5; i++) {
		for (j = 13; j < 15; j++) {
				imagen = gtk_image_new_from_file(imagenest[5]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 6; i < 11; i++) {
		for (j = 13; j < 15; j++) {
				imagen = gtk_image_new_from_file(imagenest[5]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 6; i < 13; i++) {
		for (j = 15; j < 16; j++){
			imagen = gtk_image_new_from_file(imagenest[5]);
			gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 12; i < 17; i++) {
		for (j = 13; j < 15; j++) {
				imagen = gtk_image_new_from_file(imagenest[5]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 0; i < 6; i++) {
		for (j = 15; j < 17; j++){
			imagen = gtk_image_new_from_file(imagenest[3]);
			gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 6; i < 13; i++) {
		for (j = 16; j < 17; j++){
			imagen = gtk_image_new_from_file(imagenest[3]);
			gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	for (i = 13; i < 17; i++) {
		for (j = 15; j < 17; j++){
			imagen = gtk_image_new_from_file(imagenest[3]);
			gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
		}
	}

	gtk_container_add(GTK_CONTAINER(eventbox), tablero);
	g_signal_connect(eventbox, "button-press-event", G_CALLBACK(tablero_cb), tablero);
	return eventbox;
}

