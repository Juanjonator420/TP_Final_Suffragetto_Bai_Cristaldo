#ifndef DECLARACIONESGTK_H_
#define DECLARACIONESGTK_H_

#include"declaraciones.h"
#include<gtk/gtk.h>

GtkWidget *box_tablero;
GtkWidget *label_turno;
GtkWidget *label_estado;
GtkWidget *tablero;

GtkWidget *window;
GObject *botonminfo;
GObject *botonreglas;
GObject *botoncontinuar;
GObject *botonsalir;

GtkWidget *window2;
GObject *botonatras;

GtkWidget *window3;
GObject *botonatras2;

GtkWidget *window4;
GObject *policia;
GtkWidget *cantidad_t;
GObject *suffragette;
GObject *aleatorio;
GObject *lideres;
GObject *inspectores;
GObject *jugador;
GObject *computadora;
GObject *botonaplicar;

GtkWidget *window6;
GtkWidget *ventanajuego;

const gchar *buf1;
const gchar *buf2;
const gchar *buf3;
/*const gchar *nombre_usuario;
const gchar *nombre_rival;
const gchar *ruta_dir;*/

void botonminfo_clicked_cb(GtkWidget *widget, gpointer data);
void botonatras_clicked_cb(GtkWidget *widget, gpointer data);
void botonreglas_clicked_cb(GtkWidget *widget, gpointer data);
void botonatras2_clicked_cb(GtkWidget *widget, gpointer data);
void botoncontinuar_clicked_cb(GtkWidget *widget, gpointer data);
void botonsalir_clicked_cb(GtkWidget *widget, gpointer data);
void pol_clicked_cb(GtkWidget *widget, gpointer data);
void suff_clicked_cb(GtkWidget *widget, gpointer data);
void ale_clicked_cb(GtkWidget *widget, gpointer data);
void suffs_clicked_cb(GtkWidget *widget, gpointer data);
void pols_clicked_cb(GtkWidget *widget, gpointer data);
void jugador_clicked_cb(GtkWidget *widget, gpointer data);
void computadora_clicked_cb(GtkWidget *widget, gpointer data);
void botonaplicar_clicked_cb(GtkWidget *widget, gpointer data);

void tablero_cb(GtkWidget *event_box, GdkEventButton *event, gpointer data);
GtkWidget *crear_tablero();



















#endif /* DECLARACIONESGTK_H_ */
