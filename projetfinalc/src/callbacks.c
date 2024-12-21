#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"
int sexe=1;
int armee=1;
int nuit=1;
int choi[]={0,0,0,0,0,0};
int choimod[]={0,0,0,0,0,0};
char sexeradio[10];
char armeeradio[5];
char travailradio[10];
Agent agent;
Agent updated_agent;
char cinagentamodifier[10];
const gchar *photopathajout;
const gchar *photopathmodif;
const gchar *cinpathajout;
const gchar *cinpathmodif;
const gchar *diplomepathajout;
const gchar *diplomepathmodif;
const gchar *b3ajout;
const gchar *b3modif;
const gchar *destinationfolderphoto="/home/moahmed/Downloads/Documents/Photoagents";
const gchar *destinationfolderb3="/home/moahmed/Downloads/Documents/b3agent";
const gchar *destinationfoldercin="/home/moahmed/Downloads/Documents/cinagents";
const gchar *destinationfolderdip="/home/moahmed/Downloads/Documents/diplomeagent";


void on_Login_clicked(GtkButton *button, gpointer user_data) {
    // Safely get references to widgets
    GtkWidget *window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    GtkWidget *username = lookup_widget(button, "username");
    GtkWidget *password = lookup_widget(button, "password");

    // Sanity checks to prevent null pointer dereferences
    if (!GTK_IS_WINDOW(window) || !GTK_IS_ENTRY(username) || !GTK_IS_ENTRY(password)) {
        g_warning("Invalid widget references");
        return;
    }

    const char *usr = gtk_entry_get_text(GTK_ENTRY(username));
    const char *pwd = gtk_entry_get_text(GTK_ENTRY(password));

    // Check for admin credentials first
    if ((strcmp(usr, "AdminAdmin") == 0) && (strcmp(pwd, "AdminPwd") == 0)) {
        // Correct admin credentials
        GtkWidget *Interfaceadmin = create_Interfaceadmin();

        // Keep a reference to the current window before showing the new window
        g_object_ref(window);

        gtk_widget_show(Interfaceadmin);
        gtk_widget_hide(window);

        // Use g_idle_add to safely destroy the window
        g_idle_add((GSourceFunc)gtk_widget_destroy, window);

        // Decrement reference count
        g_object_unref(window);

    } else if (validate_login_from_file(usr, pwd)) {
        // Correct client credentials
        GtkWidget *Interfaceclient = create_Interfaceclient();

        // Keep a reference to the current window before showing the new window
        g_object_ref(window);

        gtk_widget_show(Interfaceclient);
        gtk_widget_hide(window);

        // Use g_idle_add to safely destroy the window
        g_idle_add((GSourceFunc)gtk_widget_destroy, window);

        // Decrement reference count
        g_object_unref(window);

    } else {
        // Incorrect credentials
        // Ensure the window is still valid and visible before shaking
        if (GTK_IS_WINDOW(window) && gtk_widget_get_visible(window)) {
            smooth_nod_window(GTK_WINDOW(window));
        } else {
            g_warning("Window is not valid or visible for animation");
        }
    }
}



#include <stdio.h>
#include <stdlib.h>

void on_changepwd_clicked(GtkButton *button, gpointer user_data) {
    // Get the top-level window and widgets
    GtkWidget *window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    GtkWidget *username = lookup_widget(button, "username");

    // Sanity check for widgets
    if (!GTK_IS_WINDOW(window) || !GTK_IS_ENTRY(username)) {
        g_warning("Invalid widget references");
        return;
    }

    // Get the text from the username entry
    const char *usr = gtk_entry_get_text(GTK_ENTRY(username));

    // Check if the username field is empty
    if (usr == NULL || strlen(usr) == 0) {
        // Create a dialog to notify the user
        GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(window),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_WARNING,
            GTK_BUTTONS_OK,
            "To get your new password, please type your username.");

        // Run the dialog and wait for the user to respond
        gtk_dialog_run(GTK_DIALOG(dialog));

        // Destroy the dialog after use
        gtk_widget_destroy(dialog);
    } else {
        // Proceed to send email with the password
        const char *email = "mohreb3@gmail.com";
        const char *password = "14437272";

        // Construct the email command
        char command[512];
        snprintf(command, sizeof(command),
                 "echo 'Your new password is: %s' | mail -s 'Password Reset' %s",
                 password, email);

        // Execute the command
        int result = system(command);

        if (result == 0) {
            GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(window),
                GTK_DIALOG_DESTROY_WITH_PARENT,
                GTK_MESSAGE_INFO,
                GTK_BUTTONS_OK,
                "An email with your new password has been sent.");
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);
        } else {
            GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(window),
                GTK_DIALOG_DESTROY_WITH_PARENT,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_OK,
                "Failed to send the email. Please try again later.");
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);
        }
    }
}


void
on_gerercompteprincipale_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_gererreservationprincipale_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_gereavisprincipale_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_deconnecterprincipale_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Login;
  Login = create_Login ();
  gtk_widget_show (Login);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }
}


void
on_howtouseprincipal_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_disconnectbutintadmin_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Login;
  Login = create_Login ();
  gtk_widget_show (Login);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }
}




void on_dossierfichierintadmin_clicked(GtkButton *button, gpointer user_data)
{
    const char *url = "https://youtu.be/S1rWSHsGG8A";
    // Open Firefox with the specified URL
    g_spawn_async(NULL, (char *[]){"/usr/bin/firefox", (char *)url, NULL}, NULL, 0, NULL, NULL, NULL, NULL);
}


void
on_ajoutclientintadmin_clicked         (GtkWidget *objet_graphique, gpointer user_data)
{

}


void
on_gererlesserrviceintadmin_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_gererlesagentsintadmin_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Gererlesagents;
  Gererlesagents = create_Gererlesagents ();
  gtk_widget_show (Gererlesagents);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }

}


void
on_gererparkingintadmin_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_listeagents_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeModel *model;
    GtkTreeIter iter;
    GtkWidget *photoag= GTK_WIDGET(user_data);
    GtkWidget *nomag;
    GtkWidget *prenomag;
    GtkWidget *idag;
    GtkWidget *parkingag;
    nomag=lookup_widget(treeview,"nomagent");
    prenomag=lookup_widget(treeview,"prenomagent");
    idag=lookup_widget(treeview,"idagent");
    parkingag=lookup_widget(treeview,"parkingagent");
    photoag=lookup_widget(treeview,"photoagent");
    Agent agent = {0};
    g_print("Double-clicked row");
    
    



    // Get the model from the treeview
    model = gtk_tree_view_get_model(treeview);

    // Get the iterator for the clicked row
    if (gtk_tree_model_get_iter(model, &iter, path)) {
        // Variables to hold the data
        gchar *Nom;
        gchar *Prenom;
        gchar *Date;
        gchar *Cin;
        gchar *Sexe;

        // Retrieve data from the model (use & to pass addresses)
        gtk_tree_model_get(model, &iter,
                           0, &Nom,
                           1, &Prenom,
                           2, &Date,
                           3, &Cin,
                           4, &Sexe,
                           -1); // End of list

        // Print or use the retrieved data
        g_print("Double-clicked row: Nom=%s, Prenom=%s, Cin=%s\n", Nom, Prenom, Cin);

        // Copy Cin to cintoparse
        char cintoparse[50]; // Adjust size as needed
        strcpy(cintoparse, Cin);

        // Write Cin to a file
        FILE *file = fopen("stocked.txt", "w");
        if (file) {
            fprintf(file, "%s", cintoparse);
            fclose(file);
        } else {
            g_printerr("Error: Could not open stocked.txt for writing.\n");
        }
	search_agent_by_cin(cintoparse, &agent);
	gtk_label_set_text(GTK_LABEL(nomag), agent.general.name);
        gtk_label_set_text(GTK_LABEL(prenomag), agent.general.prenom);
	gtk_label_set_text(GTK_LABEL(idag), agent.general.num_cin);
	gtk_label_set_text(GTK_LABEL(parkingag), agent.work_info.parking);
	char photopath[200];
        char nomphoto[40];
	strcpy(photopath,"/home/moahmed/Downloads/Documents/Photoagents/");
	strcat(nomphoto,agent.general.num_cin);
	strcat(nomphoto,".png");
	strcat(photopath,nomphoto);
	gtk_image_set_from_file(GTK_IMAGE(photoag), photopath);
        g_print("%s",photopath);
	
	

        // Free the retrieved data
        g_free(Nom);
        g_free(Prenom);
        g_free(Date);
        g_free(Cin);
        g_free(Sexe);
    }

}


void
on_supprimeragent_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *treeview;
    treeview=lookup_widget(button,"listeagents");
    FILE *file = fopen("stocked.txt", "r");
    char cindel[10];
    fscanf(file, "%s", cindel);
    fclose(file);
    supprimer_agent(cindel);
    populate_tree_view(GTK_TREE_VIEW(treeview),"agent.txt");
}


void
on_modifieragent_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Modiferinfoagents;
  Modiferinfoagents = create_Modiferinfoagents ();
  gtk_widget_show (Modiferinfoagents);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }

}


void
on_ajouteragent_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *Ajouutagent;
    Ajouutagent = create_Ajouutagent();
    gtk_widget_show(Ajouutagent);
    GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }

}


void
on_detailagent_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Info_Agents;
  Info_Agents = create_Info_Agents ();
  gtk_widget_show (Info_Agents);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }

}
int count=0;
char mod[40];
int sortmode;

void
on_validermodtriintliste_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modsort;
GtkWidget *treeview;
treeview=lookup_widget(objet,"listeagents");
modsort=lookup_widget(objet,"comboboxsortintliste");

strcpy(mod,gtk_combo_box_get_active_text(GTK_COMBO_BOX(modsort)));
g_print("im here");
if(strcmp(mod,"Name Ascending")==0) {sortmode=1;}
else if(strcmp(mod,"Name Descending")==0) {sortmode=2;}
else if(strcmp(mod,"Cin Ascending")==0) {sortmode=3;}
else if(strcmp(mod,"Cin Descending")==0) {sortmode=4;}
printf("%d",sortmode);
printf("%s\n",mod);
sort_agents_in_file(sortmode);

populate_tree_view(GTK_TREE_VIEW(treeview),"agent.txt");
}


void
on_affresbutintliste_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *listedesreservations;
  listedesreservations = create_listedesreservations ();
  gtk_widget_show (listedesreservations);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }

}


void
on_disconnectintliste_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Login;
  Login = create_Login ();
  gtk_widget_show (Login);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }


}


void
on_homebuttonintliste_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Interfaceadmin;
  Interfaceadmin = create_Interfaceadmin ();
  gtk_widget_show (Interfaceadmin);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }


}


void
on_gererserviceintliste_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_gererparkingintliste_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_armeeoui_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))){
	  strcpy(armeeradio,"Oui");
	  armee=2;
}
}


void
on_sexeautre_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))){
	  strcpy(sexeradio,"Autre");
	  sexe=2;
}

}


void
on_sexehomme_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))){
	  strcpy(sexeradio,"Homme");
	  sexe==2;

}

}


void
on_armeenon_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	  strcpy(armeeradio,"Non");
	  armee=2;
 
}


void
on_sexefemme_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))){
	  strcpy(sexeradio,"Femme");
          sexe=2;
}
}


void
on_photopath_file_set                  (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data)
{
GtkWidget *numcin;
photopathajout = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(filechooserbutton));
g_print("Path: %s\n",photopathajout);
numcin = lookup_widget(filechooserbutton, "cinag");
const char *cinnum = gtk_entry_get_text(GTK_ENTRY(numcin));
g_print("%s",cinnum);
if (photopathajout) {
    g_print("File selected: %s\n", photopathajout);

    // Define the destination folder and the new file name
    const gchar *destination_folder = destinationfolderphoto; // Change this to your target folder
    gchar *photoname = g_strdup_printf("%s.png", cinnum); // Construct the new file name

    // Construct the new file path
    gchar *destination_path = g_build_filename(destination_folder, photoname, NULL);

    // Move and rename the file using rename()
    if (rename(photopathajout, destination_path) == 0) {
        g_print("File renamed and moved to: %s\n", destination_path);
    } else {
        perror("Error renaming/moving file");
    }

    // Free allocated memory
    g_free(photoname);
    g_free(destination_path);
} else {
    g_print("No file selected.\n");
}



}


void
on_diplomepath_file_set                (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data)
{
GtkWidget *numcin1;
diplomepathajout = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(filechooserbutton));
g_print("Path: %s\n",diplomepathajout);
numcin1 = lookup_widget(filechooserbutton, "cinag");
const char *cinnnn = gtk_entry_get_text(GTK_ENTRY(numcin1));
g_print("%s",cinnnn);
if (diplomepathajout) {
    g_print("File selected: %s\n", diplomepathajout);

    const gchar *destination_folder = destinationfolderdip;
    gchar *diplomename = g_strdup_printf("%sdip.png", cinnnn);

    gchar *destination_path = g_build_filename(destination_folder, diplomename, NULL);

    if (rename(diplomepathajout, destination_path) == 0) {
        g_print("File renamed and moved to: %s\n", destination_path);
    } else {
        perror("Error renaming/moving file");
    }

    g_free(diplomename);
    g_free(destination_path);
} else {
    g_print("No file selected.\n");
}


}


void
on_b3path_file_set                     (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data)
{
GtkWidget *numcin;
b3ajout = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(filechooserbutton));
g_print("*******\nPath: %s",b3ajout);
numcin = lookup_widget(filechooserbutton, "cinag");
const char *cin2 = gtk_entry_get_text(GTK_ENTRY(numcin));
g_print("\nCin=%s\n",cin2);
if (b3ajout) {
    g_print("File selected: %s\n", b3ajout);

    // Define the destination folder and the new file name
    const gchar *destination_folder = destinationfolderb3; 
    gchar *b3name = g_strdup_printf("%sb3.png", cin2); // Construct the new file name

    // Construct the new file path
    gchar *destination_path = g_build_filename(destination_folder, b3name, NULL);

    // Move and rename the file using rename()
    if (rename(b3ajout, destination_path) == 0) {
        g_print("File renamed and moved to: %s\n", destination_path);
    } else {
        perror("Error renaming/moving file");
    }

    // Free allocated memory
    g_free(b3name);
    g_free(destination_path);
} else {
    g_print("No file selected.\n");
}


}


void
on_cinpath_file_set                    (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data)
{
GtkWidget *numcin;
GtkWidget *buttonajout;
buttonajout=lookup_widget(filechooserbutton,"ajouteragintajout");
cinpathajout = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(filechooserbutton));
g_print("Path: %s\n",cinpathajout);
numcin = lookup_widget(filechooserbutton, "cinag");
const char *cin3 = gtk_entry_get_text(GTK_ENTRY(numcin));
g_print("%s",cin3);
if (cinpathajout) {
    g_print("File selected: %s\n", cinpathajout);

    // Define the destination folder and the new file name
    const gchar *destination_folder = destinationfoldercin;
    gchar *cinname = g_strdup_printf("%scin.png", cin3); // Construct the new file name

    // Construct the new file path
    gchar *destination_path = g_build_filename(destination_folder, cinname, NULL);

    // Move and rename the file using rename()
    if (rename(cinpathajout, destination_path) == 0) {
        g_print("File renamed and moved to: %s\n", destination_path);
    } else {
        perror("Error renaming/moving file");
    }

    // Free allocated memory
    g_free(cinname);
    g_free(destination_path);

    // Enable the "Add" button
    gtk_widget_set_sensitive(buttonajout, 1);
} else {
    g_print("No file selected.\n");
}

}


void
on_pneu_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	agent.services.control_pneus=1;
else
	agent.services.control_pneus=0;
}


void
on_mechanique_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	agent.services.check_mecanique=1;
else
	agent.services.check_mecanique=0;
}


void
on_couvrir_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	agent.services.couvrir_voiture=1;
else
	agent.services.couvrir_voiture=0;
}


void
on_vidange_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
	agent.services.vidange=1;}
else{
	agent.services.vidange=0;}

}


void
on_carburant_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
	agent.services.remplir_carburant=1;}
else{
	agent.services.remplir_carburant=0;}
}



void
on_voiturier_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
	agent.services.voiturier=1;}
else{
	agent.services.voiturier=0;}
	
}


void
on_gererparkingbutintajout_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_gerersericebutintajout_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_deconnecterbutintajout_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Login;
  Login = create_Login ();
  gtk_widget_show (Login);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }
}


void
on_homebutintajout_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Interfaceadmin;
  Interfaceadmin = create_Interfaceadmin ();
  gtk_widget_show (Interfaceadmin);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }
}


void
on_annulerajout_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
    GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(objet_graphique));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }
    GtkWidget *Gererlesagents;
    Gererlesagents = create_Gererlesagents ();
    gtk_widget_show (Gererlesagents);

}


void on_ajouterag_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
    // 1. Declaration of widgets
    GtkWidget *nomagent, *prenomagent, *bacagent, *nomdiplomeagent, *emailagent;
    GtkWidget *nomurgenceagent, *numcin, *numag, *numsec, *numurg;
    GtkWidget *jour, *mois, *annee, *apresbac, *anneebac, *anneex, *hsem, *pheur;
    GtkWidget *nag, *npark, *nres, *labelerr;

    // 2. Associate widgets
    nomagent = lookup_widget(objet_graphique, "nomag");
    prenomagent = lookup_widget(objet_graphique, "prenomag");
    bacagent = lookup_widget(objet_graphique, "bacag");
    nomdiplomeagent = lookup_widget(objet_graphique, "nomdiplome");
    emailagent = lookup_widget(objet_graphique, "mailag");
    nomurgenceagent = lookup_widget(objet_graphique, "nomcontact");
    numcin = lookup_widget(objet_graphique, "cinag");
    numag = lookup_widget(objet_graphique, "numtlfnag");
    numsec = lookup_widget(objet_graphique, "numag");
    numurg = lookup_widget(objet_graphique, "numcontact");

    jour = lookup_widget(objet_graphique, "journaissance");
    mois = lookup_widget(objet_graphique, "moisnaissance");
    annee = lookup_widget(objet_graphique, "anneenaissance");
    apresbac = lookup_widget(objet_graphique, "anneeapresbacag");
    anneebac = lookup_widget(objet_graphique, "annebacag");
    anneex = lookup_widget(objet_graphique, "annexp");
    hsem = lookup_widget(objet_graphique, "heruesemain");
    pheur = lookup_widget(objet_graphique, "prixheure");

    nag = lookup_widget(objet_graphique, "totagent");
    npark = lookup_widget(objet_graphique, "totparking");
    nres = lookup_widget(objet_graphique, "totresmoi");

    labelerr = lookup_widget(objet_graphique, "errorstream");

    // 3. Retrieve data
    // Strings
    const char *name = gtk_entry_get_text(GTK_ENTRY(nomagent));
    const char *prenom = gtk_entry_get_text(GTK_ENTRY(prenomagent));
    const char *cin = gtk_entry_get_text(GTK_ENTRY(numcin));
    const char *securite = gtk_entry_get_text(GTK_ENTRY(numsec));
    const char *bac = gtk_entry_get_text(GTK_ENTRY(bacagent));
    const char *diplome = gtk_entry_get_text(GTK_ENTRY(nomdiplomeagent));
    const char *email = gtk_entry_get_text(GTK_ENTRY(emailagent));
    const char *contact_nom = gtk_entry_get_text(GTK_ENTRY(nomurgenceagent));
    const char *contact_num = gtk_entry_get_text(GTK_ENTRY(numurg));
    const char *numtlfn = gtk_entry_get_text(GTK_ENTRY(numag));
    
    strncpy(agent.general.name, name, sizeof(agent.general.name) - 1);
    strncpy(agent.general.prenom, prenom, sizeof(agent.general.prenom) - 1);
    strncpy(agent.general.num_cin, cin, sizeof(agent.general.num_cin) - 1);
    strncpy(agent.general.num_securite_sociale, securite, sizeof(agent.general.num_securite_sociale) - 1);
    strncpy(agent.general.bac, bac, sizeof(agent.general.bac) - 1);
    strncpy(agent.experience.nom_diplome, diplome, sizeof(agent.experience.nom_diplome) - 1);
    strncpy(agent.contact.email, email, sizeof(agent.contact.email) - 1);
    strncpy(agent.contact.num_telephone, numtlfn, sizeof(agent.contact.num_telephone) - 1);
    strncpy(agent.contact.nom_contact_urgence, contact_nom, sizeof(agent.contact.nom_contact_urgence) - 1);
    strncpy(agent.contact.num_contact, contact_num, sizeof(agent.contact.num_contact) - 1);
    strncpy(agent.general.sexe, sexeradio, sizeof(agent.general.sexe) - 1);
    strncpy(agent.work_info.travaille_nuit, travailradio, sizeof(agent.work_info.travaille_nuit) - 1);
    strncpy(agent.experience.armee, armeeradio, sizeof(agent.experience.armee) - 1);

    // Spin buttons
    int jour_naiss = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
    int mois_naiss = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
    int annee_naiss = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
    snprintf(agent.general.date_naissance, sizeof(agent.general.date_naissance), "%02d-%02d-%04d", jour_naiss, mois_naiss, annee_naiss);

    agent.general.annees_apres_bac = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(apresbac));
    agent.general.annee_de_bac = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneebac));
    agent.experience.nbre_annees_experience = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneex));
    agent.work_info.heures_par_semaine = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hsem));
    agent.work_info.prix_heure = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(pheur));

    // File paths
    gchar *cinp = g_strdup_printf("%scin.png", cin);
    gchar *b3p = g_strdup_printf("%sb3.png", cin);
    gchar *dipp = g_strdup_printf("%sdip.png", cin);
    gchar *php = g_strdup_printf("%s.png", cin);

    g_print("CIN: %s\n", cin);

    strncpy(agent.documents.cin_path, cinp, sizeof(agent.documents.cin_path) - 1);
    strncpy(agent.documents.b3_path, b3p, sizeof(agent.documents.b3_path) - 1);
    strncpy(agent.documents.diplome_path, dipp, sizeof(agent.documents.diplome_path) - 1);
    strncpy(agent.documents.photo_path, php, sizeof(agent.documents.photo_path) - 1);

    g_free(cinp);
    g_free(b3p);
    g_free(dipp);
    g_free(php);

    // Set hardcoded values
    agent.work_info.salaire = 1500.0;
    strncpy(agent.work_info.parking, "parkname", sizeof(agent.work_info.parking) - 1);

    // 4. Display success message
    ajouter_agent(agent);
    gtk_label_set_text(GTK_LABEL(labelerr), "Ajout avec succès !");
    GtkWidget *current_window;
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(objet_graphique));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }
    GtkWidget *Gererlesagents;
    Gererlesagents = create_Gererlesagents();
    gtk_widget_show(Gererlesagents);
}



void
on_travaillenuitnon_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	  strcpy(travailradio,"Non");
	  nuit=2;
}


void
on_travaillenuitoui_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	  strcpy(travailradio,"Oui");
	  nuit=2;
	  
}


void
on_gererparkingintaff_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_gererserviceintaff_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_homebuttonintaff_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Interfaceadmin;
  Interfaceadmin = create_Interfaceadmin ();
  gtk_widget_show (Interfaceadmin);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }
}


void
on_fermerfenetreintaff_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Gererlesagents;
  Gererlesagents = create_Gererlesagents ();
  gtk_widget_show (Gererlesagents);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }
}


void
on_modifinfoagentintaff_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Modiferinfoagents;
  Modiferinfoagents = create_Modiferinfoagents ();
  gtk_widget_show (Modiferinfoagents);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }
}


void
on_disconnectintaff_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Login;
  Login = create_Login ();
  gtk_widget_show (Login);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }
}


void
on_trvaillenuitnon_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	  strcpy(updated_agent.work_info.travaille_nuit,"Non");

}


void
on_trvaillenuitoui_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	  strcpy(updated_agent.work_info.travaille_nuit,"Oui");


}


void
on_voituriermodif_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	updated_agent.services.voiturier=1;
else
	updated_agent.services.voiturier=0;

}


void
on_carburantmodif_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	updated_agent.services.remplir_carburant=1;
else
	updated_agent.services.remplir_carburant=0;

}


void
on_vidangemodif_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	updated_agent.services.vidange=1;
else
	updated_agent.services.vidange=0;

}


void
on_couvrirmodif_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	updated_agent.services.couvrir_voiture=1;
else
	updated_agent.services.couvrir_voiture=0;

}


void
on_mechamodif_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	updated_agent.services.check_mecanique=1;
else
	updated_agent.services.check_mecanique=0;

}


void
on_aarmeeoui_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	  strcpy(updated_agent.experience.armee,"Oui");
}


void
on_aarmeenon_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	  strcpy(updated_agent.experience.armee,"Non");

}


void
on_pneumodif_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	updated_agent.services.control_pneus=1;
else
	updated_agent.services.control_pneus=0;

}


void
on_photopathmodif_file_set             (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data)
{

}


void
on_diplomepathmodif_file_set           (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data)
{

}


void
on_b3pathmodif_file_set                (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data)
{

}


void
on_cinpathmodif_file_set               (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data)
{

}


void
on_appmodifbuttonintmod_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
    GtkWidget *emailagent;
    GtkWidget *nomurgenceagent, *numag, *numurg;
    GtkWidget *anneex, *hsem, *pheur;
    GtkWidget *dialog;
    GtkWidget *current_window;
    GtkWidget *next_window;

    FILE *file = fopen("stocked.txt", "r");
    char cinmod[15];
    fscanf(file, "%s", cinmod);
    fclose(file);

    // Fetch the agent details using the CIN
    Agent agent = {0};
    search_agent_by_cin(cinmod, &agent);

    // 2. Associate widgets
    // These declarations are for variables to be changed
    emailagent = lookup_widget(objet_graphique, "emailag");
    nomurgenceagent = lookup_widget(objet_graphique, "nomurgag");
    numag = lookup_widget(objet_graphique, "numtlfag");
    numurg = lookup_widget(objet_graphique, "numcontact");
    anneex = lookup_widget(objet_graphique, "nbrexp");
    hsem = lookup_widget(objet_graphique, "nbreheure");
    pheur = lookup_widget(objet_graphique, "prixheure");

    // 3- Retrieving data
    // Text entries
    const char *email = gtk_entry_get_text(GTK_ENTRY(emailagent));
    const char *contact_nom = gtk_entry_get_text(GTK_ENTRY(nomurgenceagent));
    const char *contact_num = gtk_entry_get_text(GTK_ENTRY(numurg));
    const char *numtlfn = gtk_entry_get_text(GTK_ENTRY(numag));

    // Spin buttons
    updated_agent.experience.nbre_annees_experience = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneex));
    updated_agent.work_info.heures_par_semaine = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hsem));
    updated_agent.work_info.prix_heure = gtk_spin_button_get_value(GTK_SPIN_BUTTON(pheur));

    strcpy(updated_agent.documents.cin_path, agent.documents.cin_path);
    strcpy(updated_agent.documents.b3_path, agent.documents.b3_path);
    strcpy(updated_agent.documents.diplome_path, agent.documents.diplome_path);
    strcpy(updated_agent.documents.photo_path, agent.documents.photo_path);
    strcpy(updated_agent.contact.num_telephone, numtlfn);
    strcpy(updated_agent.contact.email, email);
    strcpy(updated_agent.contact.nom_contact_urgence, contact_nom);
    strcpy(updated_agent.contact.num_contact, contact_num);

    if (sexe == 1) {
        strcpy(updated_agent.general.sexe, agent.general.sexe);
    }
    if (armee == 1) {
        strcpy(updated_agent.experience.armee, agent.experience.armee);
    }
    if (nuit == 1) {
        strcpy(updated_agent.work_info.travaille_nuit, agent.work_info.travaille_nuit);
    }
    sexe = 1;
    armee = 1;
    nuit = 1;

    // Call the function to modify the agent
    modifier_agent(cinmod, updated_agent);

    // Show success dialog
    dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(objet_graphique)),
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_INFO,
                                    GTK_BUTTONS_OK,
                                    "Modification successful!");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    // Close current window and open the next window
    current_window = gtk_widget_get_toplevel(objet_graphique);
    gtk_widget_destroy(current_window);

    GtkWidget *Gererlesagents;
    Gererlesagents = create_Gererlesagents ();
    gtk_widget_show (Gererlesagents);
}



void
on_annulermodifintmod_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *Gererlesagents;
    Gererlesagents = create_Gererlesagents ();
    gtk_widget_show (Gererlesagents);

    GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }

}


void
on_disconnectintmod_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Login;
  Login = create_Login ();
  gtk_widget_show (Login);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }
}


void
on_gererserviceintmod_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_gererparkingintmod_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_homebuttonintmod_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Interfaceadmin;
  Interfaceadmin = create_Interfaceadmin ();
  gtk_widget_show (Interfaceadmin);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }
}


void
on_listedesreservationpardate_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
    
}





void
on_gererparkingintres_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_gererserviceintres_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_disconnectintres_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Login;
  Login = create_Login ();
  gtk_widget_show (Login);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }
}


void
on_homebuttonintres_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Interfaceadmin;
  Interfaceadmin = create_Interfaceadmin ();
  gtk_widget_show (Interfaceadmin);
  GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }
}


void
on_returnbuttonintres_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *Gererlesagents;
    Gererlesagents = create_Gererlesagents ();
    gtk_widget_show (Gererlesagents);

    GtkWidget *current_window;    
    current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    if (GTK_IS_WIDGET(current_window)) {
        gtk_widget_destroy(current_window);
    } else {
        g_warning("Current window is not a valid GTK widget!");
    }
}


void
on_validerdatereservationintres_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *date;
    GtkWidget *liste;
    GtkWidget *dialog;
    liste = lookup_widget(objet, "listedesreservationpardate");

    date = lookup_widget(objet, "datereservation");
    int day, month, year;
    const gchar *datestr = gtk_entry_get_text(GTK_ENTRY(date));

    // Validate date format
    if (sscanf(datestr, "%d-%d-%d", &day, &month, &year) != 3 || day < 1 || day > 31 || month < 1 || month > 12 || year < 1) {
        dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(objet)),
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_ERROR,
                                        GTK_BUTTONS_OK,
                                        "Invalid date format! Please enter the date in DD-MM-YYYY format.");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }

    // Filter reservations and populate treeview
    filterReservationsByDate("reservation.txt", "filtered.txt", day, month, year);


    populate_treeview_from_file(GTK_TREE_VIEW(liste), "filtered.txt");
}


void
on_Confirmerauth_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_annulerauth_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_cinag_editing_done                  (GtkCellEditable *celleditable,
                                        gpointer         user_data)
{

}
void
on_cinag_changed                       (GtkEditable     *editable,
                                        gpointer         user_data)
{
    // Retrieve the text from the GtkEditable widget (which could be a GtkEntry)
    const gchar *final_text = gtk_entry_get_text(GTK_ENTRY(editable));
    g_print("Current text: %s\n", final_text);  // Print the current text

    GtkWidget *cinpath, *photopath, *b3path, *diplomepath;

    // Look up the widgets by their names
    cinpath = lookup_widget(editable, "cinpath");
    photopath = lookup_widget(editable, "photopath");
    b3path = lookup_widget(editable, "b3path");
    diplomepath = lookup_widget(editable, "diplomepath");

    // Compare the text from the entry widget
    if (strlen(final_text) ==8) {
        // Enable the widgets if the entered text matches
        gtk_widget_set_sensitive(cinpath, TRUE);
        gtk_widget_set_sensitive(b3path, TRUE);
        gtk_widget_set_sensitive(diplomepath, TRUE);
        gtk_widget_set_sensitive(photopath, TRUE);
    } else {
        // Disable the widgets if the entered text doesn't match
        gtk_widget_set_sensitive(cinpath, FALSE);
        gtk_widget_set_sensitive(b3path, FALSE);
        gtk_widget_set_sensitive(diplomepath, FALSE);
        gtk_widget_set_sensitive(photopath, FALSE);
    }
}



void
on_showpwd_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *password;
password=lookup_widget(togglebutton,"password");
if (gtk_toggle_button_get_active(togglebutton)){
	gtk_entry_set_visibility(password, 1);

}
else{gtk_entry_set_visibility(password, 0);}


}

