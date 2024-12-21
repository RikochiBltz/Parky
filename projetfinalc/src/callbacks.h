#include <gtk/gtk.h>


void
on_Login_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_changepwd_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_gerercompteprincipale_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_gererreservationprincipale_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_gereavisprincipale_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_deconnecterprincipale_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_howtouseprincipal_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_disconnectbutintadmin_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_dossierfichierintadmin_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajoutclientintadmin_clicked         (GtkWidget *objet_graphique, gpointer user_data);

void
on_gererlesserrviceintadmin_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_gererlesagentsintadmin_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_gererparkingintadmin_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_listeagents_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_supprimeragent_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifieragent_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouteragent_clicked(GtkButton *button, gpointer user_data);

void
on_detailagent_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_validermodtriintliste_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_affresbutintliste_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_disconnectintliste_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_homebuttonintliste_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_gererserviceintliste_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_gererparkingintliste_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_armeeoui_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_sexeautre_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_sexehomme_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_armeenon_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_sexefemme_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_photopath_file_set                  (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data);

void
on_diplomepath_file_set                (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data);

void
on_b3path_file_set                     (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data);

void
on_cinpath_file_set                    (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data);

void
on_pneu_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_mechanique_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_couvrir_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_vidange_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_carburant_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_voiturier_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gererparkingbutintajout_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_gerersericebutintajout_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_deconnecterbutintajout_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_homebutintajout_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_annulerajout_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ajouterag_clicked                   (GtkWidget *objet_graphique, gpointer user_data);

void
on_travaillenuitnon_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_travaillenuitoui_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gererparkingintaff_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_gererserviceintaff_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_homebuttonintaff_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_fermerfenetreintaff_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifinfoagentintaff_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_disconnectintaff_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_trvaillenuitnon_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_trvaillenuitoui_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_voituriermodif_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_carburantmodif_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_vidangemodif_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_couvrirmodif_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_mechamodif_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_aarmeeoui_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_aarmeenon_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_pneumodif_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_photopathmodif_file_set             (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data);

void
on_diplomepathmodif_file_set           (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data);

void
on_b3pathmodif_file_set                (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data);

void
on_cinpathmodif_file_set               (GtkFileChooserButton *filechooserbutton,
                                        gpointer         user_data);

void
on_appmodifbuttonintmod_clicked(GtkWidget *objet_graphique, gpointer user_data);

void
on_annulermodifintmod_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_disconnectintmod_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_gererserviceintmod_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_gererparkingintmod_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_homebuttonintmod_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_listedesreservationpardate_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_gererparkingintres_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_gererserviceintres_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_disconnectintres_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_homebuttonintres_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_returnbuttonintres_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_validerdatereservationintres_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Confirmerauth_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_annulerauth_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_cinag_editing_done                  (GtkCellEditable *celleditable,
                                        gpointer         user_data);

void
on_cinag_changed                       (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_showpwd_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
