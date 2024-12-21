
#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdio.h>
#include <gtk/gtk.h>


typedef struct {
    char name[50];
    char prenom[50];
    char date_naissance[20];
    char num_cin[20];
    char sexe[10];
    char num_securite_sociale[20];
    char bac[50];
    int annees_apres_bac;
    int annee_de_bac;
} GeneralInfo;


typedef struct {
    int nbre_annees_experience;
    char nom_diplome[50];
    char armee[10];
} Experience;


typedef struct {
    char num_telephone[20];
    char email[50];
    char nom_contact_urgence[50];
    char num_contact[20];
} Contact;


typedef struct {
    int control_pneus;
    int check_mecanique;
    int couvrir_voiture;
    int vidange;
    int remplir_carburant;
    int voiturier;
} Services;


typedef struct {
    char cin_path[100];
    char b3_path[100];
    char diplome_path[100];
    char photo_path[100];
} Documents;


typedef struct {
    char travaille_nuit[10];
    int heures_par_semaine;
    float prix_heure;
    float salaire;
    char parking[100];
} WorkInfo;


typedef struct {
    GeneralInfo general;
    Experience experience;
    Contact contact;
    Services services;
    Documents documents;
    WorkInfo work_info;
} Agent;
typedef struct { 
int id_res; 
int cin; 
char nom[10]; 
char city[15]; 
char gouvernorat[15]; 
int jour; 
int mois; 
int annee; 
int heuredebut; 
int minutedebut; 
int heurefin; 
int minutefin; 
int sexe;// 0 pour femme et 1 pour homme int retard[2]; } Reservation;
int retard[2];
}Reservation;
typedef struct {
    GtkWindow *window;
    int original_x;
    int original_y;
    int step;
    int direction;   // -1: left, 1: right
    int max_offset;  // Total offset distance (pixels)
    int total_steps; // Total steps for smooth movement
} SmoothNodData;
typedef struct {
    char username[50];
    char password[50];
} login;

void ajouter_agent(Agent agent);
int modifier_agent(const char *cin, Agent updated_agent);
int supprimer_agent(const char *cin);
int afficher_agent(const char *cin);
void sort_agents_in_file(int choice);
void searchAgent(int searchType, const char *searchValue);
int search_agent_by_cin(const char *cin, Agent *agent);
void populate_tree_view(GtkTreeView *tree_view, const char *filename);
void setup_tree_view(GtkTreeView *tree_view);
void update_agent_details(const char *file_path, GtkWidget *nomagent, GtkWidget *prenomagent,
                          GtkWidget *datenaissanceagent, GtkWidget *cinagent, GtkWidget *sexeagent,
                          GtkWidget *numsecag, GtkWidget *bacag, GtkWidget *anneapresbacag,
                          GtkWidget *annebacag, GtkWidget *anneeperience, GtkWidget *nomdiplomeagent,
                          GtkWidget *armeeagent, GtkWidget *numtlfnagents, GtkWidget *emilagent,
                          GtkWidget *nomurg, GtkWidget *numurg, GtkWidget *pneu, GtkWidget *mechanique,
                          GtkWidget *couvrir, GtkWidget *vidange, GtkWidget *carburant,
                          GtkWidget *voiturier, GtkWidget *cinpathtext, GtkWidget *b3path,
                          GtkWidget *diplomepath, GtkWidget *photopath, GtkWidget *travaillernuit,
                          GtkWidget *nbrheure, GtkWidget *prixheure, GtkWidget *salaireag,
                          GtkWidget *parkingag);
int count_lines(const char *filename);
void update_count_labels(GtkWidget *nbrparking, GtkWidget *nbragents, GtkWidget *nbrdesreservation);
double custom_smooth_interpolate(double t);
gboolean smooth_nod_callback(gpointer data);
void smooth_nod_window(GtkWindow *window);
void filterReservationsByDate(const char* inputFilename, const char* outputFilename, int day, int month, int year);
void populate_treeview_from_file(GtkTreeView *treeview, const char *filename);
void setup_treeview_columns(GtkTreeView *treeview);
int validate_login_from_file(const char *usr, const char *pwd);
void send_email();
//void sexetoggle(int sexe, char sexechar);
//void armeetoggle(int armee, char ouinon);
//void sexetoggle(int nuit, char travnuit);
#endif
