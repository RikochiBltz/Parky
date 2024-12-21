
#include "fonctions.h"
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>



int modifier_agent(const char *cin, Agent updated_agent)
{
    Agent agent={0};
    search_agent_by_cin(cin,&agent);
    supprimer_agent(cin);
    agent.experience.nbre_annees_experience=updated_agent.experience.nbre_annees_experience;
    agent.work_info.heures_par_semaine=updated_agent.work_info.heures_par_semaine;
    agent.work_info.prix_heure=updated_agent.work_info.prix_heure;
    strcpy(agent.documents.cin_path,updated_agent.documents.cin_path);
    strcpy(agent.documents.b3_path,updated_agent.documents.b3_path);
    strcpy(agent.documents.diplome_path,updated_agent.documents.diplome_path);
    strcpy(agent.documents.photo_path,updated_agent.documents.photo_path);
    strcpy(agent.contact.num_telephone,updated_agent.contact.num_telephone);
    strcpy(agent.contact.email,updated_agent.contact.email);
    strcpy(agent.contact.nom_contact_urgence,updated_agent.contact.nom_contact_urgence);
    strcpy(agent.contact.num_contact,updated_agent.contact.num_contact);

    agent.services.control_pneus=updated_agent.services.control_pneus;
    agent.services.check_mecanique=updated_agent.services.check_mecanique;
    agent.services.couvrir_voiture=updated_agent.services.couvrir_voiture;
    agent.services.vidange=updated_agent.services.vidange;
    agent.services.remplir_carburant=updated_agent.services.remplir_carburant;
    agent.services.voiturier=updated_agent.services.voiturier;

    strcpy(agent.work_info.travaille_nuit,updated_agent.work_info.travaille_nuit);
    strcpy(agent.experience.armee,updated_agent.experience.armee);
    ajouter_agent(agent);

    
}

void ajouter_agent(Agent agent)
{
    //n7el el fichier en mode append bch najem nzid el agents f ekhr el fichier
    FILE *file = fopen("agent.txt", "a");
//hehdi condition d'erreur tprinti el error fil erroe stream ba3ed bch na7iha bch nbadalha b printf f label
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    // hne bch nzid agent w les information bch ykounou seppare par un espace
    fprintf(file,
            "%s %s %s %s %s %s %s %d %d "      // General Info
            "%d %s %s "                        // Experience
            "%s %s %s %s "                     // Contact
            "%d %d %d %d %d %d "               // Services
            "%s %s %s %s "                     // Documents
            "%s %d %.2f %.2f %s\n",            // Work Info (including parking)
            // General Info
            agent.general.name,
            agent.general.prenom,
            agent.general.date_naissance,
            agent.general.num_cin,
            agent.general.sexe,
            agent.general.num_securite_sociale,
            agent.general.bac,
            agent.general.annees_apres_bac,
            agent.general.annee_de_bac,
            // Experience
            agent.experience.nbre_annees_experience,
            agent.experience.nom_diplome,
            agent.experience.armee,
            // Contact
            agent.contact.num_telephone,
            agent.contact.email,
            agent.contact.nom_contact_urgence,
            agent.contact.num_contact,
            // Services
            agent.services.control_pneus,
            agent.services.check_mecanique,
            agent.services.couvrir_voiture,
            agent.services.vidange,
            agent.services.remplir_carburant,
            agent.services.voiturier,
            // Documents
            agent.documents.cin_path,
            agent.documents.b3_path,
            agent.documents.diplome_path,
            agent.documents.photo_path,
            // Work Info
            agent.work_info.travaille_nuit,
            agent.work_info.heures_par_semaine,
            agent.work_info.prix_heure,
            agent.work_info.salaire,
            agent.work_info.parking
           );

    fclose(file);
}




int supprimer_agent(const char *cin)
{
    FILE *file = fopen("agent.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file for reading");
        return -1;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL)
    {
        perror("Error opening temporary file");
        fclose(file);
        return -1;
    }

    char line[1024];
    int found = 0;
    while (fgets(line, sizeof(line), file))
    {
        Agent current_agent;
        sscanf(line,
               "%s %s %s %s %s %s %s %d %d "
               "%d %s %s "
               "%s %s %s %s "
               "%d %d %d %d %d %d "
               "%s %s %s %s "
               "%s %d %f %f %s",
               // General Info
               current_agent.general.name,
               current_agent.general.prenom,
               current_agent.general.date_naissance,
               current_agent.general.num_cin,
               current_agent.general.sexe,
               current_agent.general.num_securite_sociale,
               current_agent.general.bac,
               &current_agent.general.annees_apres_bac,
               &current_agent.general.annee_de_bac,
               // Experience
               &current_agent.experience.nbre_annees_experience,
               current_agent.experience.nom_diplome,
               current_agent.experience.armee,
               // Contact
               current_agent.contact.num_telephone,
               current_agent.contact.email,
               current_agent.contact.nom_contact_urgence,
               current_agent.contact.num_contact,
               // Services
               &current_agent.services.control_pneus,
               &current_agent.services.check_mecanique,
               &current_agent.services.couvrir_voiture,
               &current_agent.services.vidange,
               &current_agent.services.remplir_carburant,
               &current_agent.services.voiturier,
               // Documents
               current_agent.documents.cin_path,
               current_agent.documents.b3_path,
               current_agent.documents.diplome_path,
               current_agent.documents.photo_path,
               // Work Info
               current_agent.work_info.travaille_nuit,
               &current_agent.work_info.heures_par_semaine,
               &current_agent.work_info.prix_heure,
               &current_agent.work_info.salaire,
               current_agent.work_info.parking
              );

        if (strcmp(current_agent.general.num_cin, cin) == 0)
        {
            // hne nafs el khedma ta3 el modifier sauf wa9telli yal9a el ligne bech yskippi maghir mayktbou
            found = 1;
            continue;
        }

        //hne nekteb el ligne b fonction fputs
        fputs(line, temp);
    }

    fclose(file);
    fclose(temp);
//kifkif hne ken l9a bch yfskh agent w yaamal rename l temp snn ykhali kol chay w yfskh temp
    if (found)
    {
        remove("agent.txt");
        rename("temp.txt", "agent.txt");
        return 1;
    }
    else
    {
        remove("temp.txt");
        return 0;
    }
}


int afficher_agent(const char *cin)
{
    FILE *file = fopen("agent.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    char line[2048];
    int found = 0;

    while (fgets(line, sizeof(line), file))
    {
        Agent current_agent;
        // kif kif hne bech yparsi les donnes f line (hne manich fehem aleh kif atitou 1024 longeur ta3 ligne dakhlet fil 7it kif 7attitha 2048 mchet cv)
        sscanf(line,
               "%s %s %s %s %s %s %s %d %d "
               "%d %s %s "
               "%s %s %s %s "
               "%d %d %d %d %d %d "
               "%s %s %s %s "
               "%s %d %f %f %s",
               // General Info
               current_agent.general.name,
               current_agent.general.prenom,
               current_agent.general.date_naissance,
               current_agent.general.num_cin,
               current_agent.general.sexe,
               current_agent.general.num_securite_sociale,
               current_agent.general.bac,
               &current_agent.general.annees_apres_bac,
               &current_agent.general.annee_de_bac,
               // Experience
               &current_agent.experience.nbre_annees_experience,
               current_agent.experience.nom_diplome,
               current_agent.experience.armee,
               // Contact
               current_agent.contact.num_telephone,
               current_agent.contact.email,
               current_agent.contact.nom_contact_urgence,
               current_agent.contact.num_contact,
               // Services
               &current_agent.services.control_pneus,
               &current_agent.services.check_mecanique,
               &current_agent.services.couvrir_voiture,
               &current_agent.services.vidange,
               &current_agent.services.remplir_carburant,
               &current_agent.services.voiturier,
               // Documents
               current_agent.documents.cin_path,
               current_agent.documents.b3_path,
               current_agent.documents.diplome_path,
               current_agent.documents.photo_path,
               // Work Info
               current_agent.work_info.travaille_nuit,
               &current_agent.work_info.heures_par_semaine,
               &current_agent.work_info.prix_heure,
               &current_agent.work_info.salaire,
               current_agent.work_info.parking
              );

        if (strcmp(current_agent.general.num_cin, cin) == 0)
        {
            // hne ken l9a cin bch yeprinti les informations 
            printf("----- Agent Details -----\n");
            printf("Name: %s %s\n", current_agent.general.name, current_agent.general.prenom);
            printf("Date de Naissance: %s\n", current_agent.general.date_naissance);
            printf("CIN: %s\n", current_agent.general.num_cin);
            printf("Sexe: %s\n", current_agent.general.sexe);
            printf("Num. Securite Sociale: %s\n", current_agent.general.num_securite_sociale);
            printf("Bac: %s\n", current_agent.general.bac);
            printf("Annees Apres Bac: %d\n", current_agent.general.annees_apres_bac);
            printf("Annee De Bac: %d\n", current_agent.general.annee_de_bac);

            printf("\nExperience:\n");
            printf("  Nombre d'annees d'experience: %d\n", current_agent.experience.nbre_annees_experience);
            printf("  Nom Diplome: %s\n", current_agent.experience.nom_diplome);
            printf("  Armee: %s\n", current_agent.experience.armee);

            printf("\nContact:\n");
            printf("  Telephone: %s\n", current_agent.contact.num_telephone);
            printf("  Email: %s\n", current_agent.contact.email);
            printf("  Contact Urgence: %s\n", current_agent.contact.nom_contact_urgence);
            printf("  Numero Contact: %s\n", current_agent.contact.num_contact);

            printf("\nServices:\n");
            printf("  Control des Pneus: %d\n", current_agent.services.control_pneus);
            printf("  Check Mecanique: %d\n", current_agent.services.check_mecanique);
            printf("  Couvrir Voiture: %d\n", current_agent.services.couvrir_voiture);
            printf("  Vidange: %d\n", current_agent.services.vidange);
            printf("  Remplir Carburant: %d\n", current_agent.services.remplir_carburant);
            printf("  Voiturier: %d\n", current_agent.services.voiturier);

            printf("\nDocuments:\n");
            printf("  CIN Path: %s\n", current_agent.documents.cin_path);
            printf("  B3 Path: %s\n", current_agent.documents.b3_path);
            printf("  Diplome Path: %s\n", current_agent.documents.diplome_path);
            printf("  Photo Path: %s\n", current_agent.documents.photo_path);

            printf("\nWork and Salary:\n");
            printf("  Travail de Nuit: %s\n", current_agent.work_info.travaille_nuit);
            printf("  Heures Par Semaine: %d\n", current_agent.work_info.heures_par_semaine);
            printf("  Prix Par Heure: %.2f\n", current_agent.work_info.prix_heure);
            printf("  Salaire: %.2f\n", current_agent.work_info.salaire);
            printf("  Parking Address: %s\n", current_agent.work_info.parking);
            printf("-------------------------\n");
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found)
    {
        printf("Agent with CIN %s not found.\n", cin);
    }

    return found;
}



//hne bech nebda bil les sous fonctions ta3 sort agent
//hehdom bch yekkhdmou fil paramtere ta3 qsort


int compare_name_asc(const void *a, const void *b)
{
//les deux lignes hedhom bch naamal casting ta3 el agenta w agentb al agent * bch najem nekhou el acces lil fields ta3hom aka data elli fi wost kol wa7ed sinin manjmch
//el casting de pointerus ysahhal aliya el khedma bil qsort khtr najm nekhdem m3a ay type ta3 data
//void * yetsamma generic pointer ynjm ypointi ala ay tyoe ta3 data
//const tkhallih read only mnjmch nbdl fih
    Agent *agentA = (Agent *)a;
    Agent *agentB = (Agent *)b;
//hne strcmp tcompari b code asci ta3mal deja comparaison ascendante 
    int cmp = strcmp(agentA->general.name, agentB->general.name);
    if (cmp == 0)
    {
        return strcmp(agentA->general.prenom, agentB->general.prenom);
    }
    return cmp;
}

int compare_name_desc(const void *a, const void *b)
{
//kifkif hne ken sa2louni aleha nejbedlhom el exemple ta3 el box 
//strcmp men annd rabbi comparaison ascendante
    Agent *agentA = (Agent *)a;
    Agent *agentB = (Agent *)b;
    int cmp = strcmp(agentB->general.name, agentA->general.name);
    if (cmp == 0)
    {
        return strcmp(agentB->general.prenom, agentA->general.prenom);
    }
    return cmp;
}

int compare_cin_asc(const void *a, const void *b)

{
    Agent *agentA = (Agent *)a;
    Agent *agentB = (Agent *)b;
    return strcmp(agentA->general.num_cin, agentB->general.num_cin);
}

int compare_cin_desc(const void *a, const void *b)
{
    Agent *agentA = (Agent *)a;
    Agent *agentB = (Agent *)b;
    return strcmp(agentB->general.num_cin, agentA->general.num_cin);
}
//sort elli bech naamalha bech nestaamel liste w nsorteha b q sort
void sort_agents_in_file(int choice)
{
    Agent agents[1024];
    int num_agents = 0;

    
    FILE *file = fopen("agent.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    
    while (fscanf(file,
                  "%s %s %s %s %s %s %s %d %d "
                  "%d %s %s "
                  "%s %s %s %s "
                  "%d %d %d %d %d %d "
                  "%s %s %s %s "
                  "%s %d %f %f %s\n",
                  // General Info
                  agents[num_agents].general.name,
                  agents[num_agents].general.prenom,
                  agents[num_agents].general.date_naissance,
                  agents[num_agents].general.num_cin,
                  agents[num_agents].general.sexe,
                  agents[num_agents].general.num_securite_sociale,
                  agents[num_agents].general.bac,
                  &agents[num_agents].general.annees_apres_bac,
                  &agents[num_agents].general.annee_de_bac,
                  // Experience
                  &agents[num_agents].experience.nbre_annees_experience,
                  agents[num_agents].experience.nom_diplome,
                  agents[num_agents].experience.armee,
                  // Contact
                  agents[num_agents].contact.num_telephone,
                  agents[num_agents].contact.email,
                  agents[num_agents].contact.nom_contact_urgence,
                  agents[num_agents].contact.num_contact,
                  // Services
                  &agents[num_agents].services.control_pneus,
                  &agents[num_agents].services.check_mecanique,
                  &agents[num_agents].services.couvrir_voiture,
                  &agents[num_agents].services.vidange,
                  &agents[num_agents].services.remplir_carburant,
                  &agents[num_agents].services.voiturier,
                  // Documents
                  agents[num_agents].documents.cin_path,
                  agents[num_agents].documents.b3_path,
                  agents[num_agents].documents.diplome_path,
                  agents[num_agents].documents.photo_path,
                  // Work Info
                  agents[num_agents].work_info.travaille_nuit,
                  &agents[num_agents].work_info.heures_par_semaine,
                  &agents[num_agents].work_info.prix_heure,
                  &agents[num_agents].work_info.salaire,
                  agents[num_agents].work_info.parking
                 ) != EOF)
    {
        num_agents++;
        if (num_agents >= 1024)
        {
            printf("Maximum number of agents reached.\n");
            break;
        }
    }

    fclose(file);

   
    int (*compare)(const void *, const void *) = NULL;
    if(choice==1){ // Sort by name and surname ascending
        compare = compare_name_asc;
        printf("%s","nameasc\n");}
    else if(choice==2){ // Sort by name and surname descending
        compare = compare_name_desc;
        printf("%s","namedsc\n");
}
    else if(choice==3){ // Sort by CIN ascending
        compare = compare_cin_asc;
        printf("%s","cinasc\n");
}
    else if(choice==4){ // Sort by CIN descending
        compare = compare_cin_desc;
        printf("%s","cindsc\n");
}

//hne qsort bech to93od tappeli f compare kol marra w taateha 2 valeurs m tableau tekhdem bihom w tsortihom w compare hiya poiter ala les 4 fonctions elli lfou9 ta3a sorting 
    if (compare != NULL)
    {
        qsort(agents, num_agents, sizeof(Agent), compare);
    }

//hne bech n7ellou el fichier mode write bech nektbou el sorted table elli amalneh lfou9
    file = fopen("agent.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file for writing");
        return;
    }

    for (int i = 0; i < num_agents; i++)
    {
        fprintf(file,
                "%s %s %s %s %s %s %s %d %d "
                "%d %s %s "
                "%s %s %s %s "
                "%d %d %d %d %d %d "
                "%s %s %s %s "
                "%s %d %.2f %.2f %s\n",
                // General Info
                agents[i].general.name,
                agents[i].general.prenom,
                agents[i].general.date_naissance,
                agents[i].general.num_cin,
                agents[i].general.sexe,
                agents[i].general.num_securite_sociale,
                agents[i].general.bac,
                agents[i].general.annees_apres_bac,
                agents[i].general.annee_de_bac,
                // Experience
                agents[i].experience.nbre_annees_experience,
                agents[i].experience.nom_diplome,
                agents[i].experience.armee,
                // Contact
                agents[i].contact.num_telephone,
                agents[i].contact.email,
                agents[i].contact.nom_contact_urgence,
                agents[i].contact.num_contact,
                // Services
                agents[i].services.control_pneus,
                agents[i].services.check_mecanique,
                agents[i].services.couvrir_voiture,
                agents[i].services.vidange,
                agents[i].services.remplir_carburant,
                agents[i].services.voiturier,
                // Documents
                agents[i].documents.cin_path,
                agents[i].documents.b3_path,
                agents[i].documents.diplome_path,
                agents[i].documents.photo_path,
                // Work Info
                agents[i].work_info.travaille_nuit,
                agents[i].work_info.heures_par_semaine,
                agents[i].work_info.prix_heure,
                agents[i].work_info.salaire,
                agents[i].work_info.parking
               );
    }

    fclose(file);

    printf("Agents sorted successfully based on choice %d.\n", choice);
}
//hedhi el fonctions ta3 recherche bech nestaamalh fil liste ta3 les agents mazalet bch nzidha d'autre filtre ama pour le moment c fonctionnel
void searchAgent(int searchType, const char *searchValue) {
    FILE *file = fopen("agent.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open agent.txt\n");
        return;
    }

    char line[4096];
    Agent agent;

    int found = 0;
//hne el fonction bech to93od tpassi fil les linee sel kol bch tchouf bil search type chkoun elli nlwj alih 7attekch takhlat end of file (mouch lezem nekteb end of file hne) /najjam nekteb 9adeh num d'agents bch naateha condition ama hatta hakka tekhdem normale andha el conddiion te3ha

    while (fgets(line, sizeof(line), file)) {
        sscanf(line,
               "%s %s %s %19s %s %s %s %d %d "      // General Info
               "%d %s %s "                        // Experience
               "%s %s %s %s "                     // Contact
               "%d %d %d %d %d %d "               // Services
               "%s %s %s %s "                     // Documents
               "%s %d %f %f %s\n",            // Work Info (including parking)
               agent.general.name,
               agent.general.prenom,
               agent.general.date_naissance,
               agent.general.num_cin,
               agent.general.sexe,
               agent.general.num_securite_sociale,
               agent.general.bac,
               &agent.general.annees_apres_bac,
               &agent.general.annee_de_bac,
               // Experience
               &agent.experience.nbre_annees_experience,
               agent.experience.nom_diplome,
               agent.experience.armee,
               // Contact
               agent.contact.num_telephone,
               agent.contact.email,
               agent.contact.nom_contact_urgence,
               agent.contact.num_contact,
               // Services
               &agent.services.control_pneus,
               &agent.services.check_mecanique,
               &agent.services.couvrir_voiture,
               &agent.services.vidange,
               &agent.services.remplir_carburant,
               &agent.services.voiturier,
               // Documents
               agent.documents.cin_path,
               agent.documents.b3_path,
               agent.documents.diplome_path,
               agent.documents.photo_path,
               // Work Info
               agent.work_info.travaille_nuit,
               &agent.work_info.heures_par_semaine,
               &agent.work_info.prix_heure,
               &agent.work_info.salaire,
               agent.work_info.parking
               );

        switch (searchType) {
            case 1: 
                if (strcmp(agent.general.num_cin, searchValue) == 0) {
                    printf("Agent found by CIN:\n");
                    printf("Name: %s %s\n", agent.general.name, agent.general.prenom);
                    printf("CIN: %s\n", agent.general.num_cin);
                    printf("Parking: %s\n", agent.work_info.parking);
                    printf("Contact: %s\n\n", agent.contact.num_telephone);
                    found = 1;
                }
                break;

            case 2:
                if (strcmp(agent.general.name, searchValue) == 0) {
                    printf("Agent found by Name:\n");
                    printf("Name: %s %s\n", agent.general.name, agent.general.prenom);
                    printf("CIN: %s\n", agent.general.num_cin);
                    printf("Parking: %s\n", agent.work_info.parking);
                    printf("Contact: %s\n\n", agent.contact.num_telephone);
                    found = 1;
                }
                break;
            default:
                printf("Invalid search type.\n");
                fclose(file);
                return;
        }

        // bech ye9ef ken el name walla cin l9ahom khtr 2 deux sont uniques
        if (found && (searchType == 1 || searchType == 2)) {
            break;
        }
    }

    if (!found) {
        printf("No agents found for the specified search criteria.\n");
    }

    fclose(file);
}

/*void sexetoggle(int sexe, char sexechar){
	if(sexe == 1)
		strcpy(sexechar,"homme");
	if(sexe == 2)
		strcpy(sexechar,"femme");
	else if(sexe == 3)
		strcpy(sexechar,"autre");
}
void armeetoggle(int armee, char ouinon){
	if(armee == 1)
		strcpy(ouinon,"oui");
	else if(armee == 2)
		strcpy(ouinon,"non");
}
void sexetoggle(int nuit, char travnuit){
	if(nuit == 1)
		strcpy(travnuit,"oui");
	else if(nuit == 2)
		strcpy(travnuit,"non");
}
*/
int search_agent_by_cin(const char *cin, Agent *agent) {
    FILE *file = fopen("agent.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0; // Return 0 to indicate failure
    }

    char line[2048];
    while (fgets(line, sizeof(line), file)) {
        Agent temp_agent;

        // Parse the line into the temporary Agent structure
        sscanf(line,
               "%s %s %s %s %s %s %s %d %d "
               "%d %s %s "
               "%s %s %s %s "
               "%d %d %d %d %d %d "
               "%s %s %s %s "
               "%s %d %f %f %s",
               // General Info
               temp_agent.general.name,
               temp_agent.general.prenom,
               temp_agent.general.date_naissance,
               temp_agent.general.num_cin,
               temp_agent.general.sexe,
               temp_agent.general.num_securite_sociale,
               temp_agent.general.bac,
               &temp_agent.general.annees_apres_bac,
               &temp_agent.general.annee_de_bac,
               // Experience
               &temp_agent.experience.nbre_annees_experience,
               temp_agent.experience.nom_diplome,
               temp_agent.experience.armee,
               // Contact
               temp_agent.contact.num_telephone,
               temp_agent.contact.email,
               temp_agent.contact.nom_contact_urgence,
               temp_agent.contact.num_contact,
               // Services
               &temp_agent.services.control_pneus,
               &temp_agent.services.check_mecanique,
               &temp_agent.services.couvrir_voiture,
               &temp_agent.services.vidange,
               &temp_agent.services.remplir_carburant,
               &temp_agent.services.voiturier,
               // Documents
               temp_agent.documents.cin_path,
               temp_agent.documents.b3_path,
               temp_agent.documents.diplome_path,
               temp_agent.documents.photo_path,
               // Work Info
               temp_agent.work_info.travaille_nuit,
               &temp_agent.work_info.heures_par_semaine,
               &temp_agent.work_info.prix_heure,
               &temp_agent.work_info.salaire,
               temp_agent.work_info.parking);

        // Check if the CIN matches
        if (strcmp(temp_agent.general.num_cin, cin) == 0) {
            // Copy the found agent data into the provided structure
            *agent = temp_agent;
            fclose(file);
            return 1; // Return 1 to indicate success
        }
    }

    fclose(file);
    return 0; // Return 0 if no match is found
}
void populate_tree_view(GtkTreeView *tree_view, const char *filename) {
    GtkListStore *list_store = gtk_list_store_new(5, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING); // 5 colonnes
    GtkTreeIter iter;

    FILE *file = fopen(filename, "r");
    if (!file) {
        g_printerr("Error: Could not open file %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char Nom[50], Prenom[100], Date[50], Cin[20], Sexe[10];
        if (sscanf(line, "%s %s %s %s %s", Nom, Prenom, Date, Cin, Sexe) == 5) {
            gtk_list_store_append(list_store, &iter); // Add a new row
            gtk_list_store_set(list_store, &iter,
                               0, Nom,
                               1, Prenom,
                               2, Date,
			       3, Cin,
			       4, Sexe,
                               -1);
        }
    }
    fclose(file);

    gtk_tree_view_set_model(tree_view, GTK_TREE_MODEL(list_store));
    g_object_unref(list_store); // Decrease reference count
}
void setup_tree_view(GtkTreeView *tree_view) {
    GtkCellRenderer *renderer = gtk_cell_renderer_text_new();

    GtkTreeViewColumn *col1 = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", 0, NULL);
    GtkTreeViewColumn *col2 = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", 1, NULL);
    GtkTreeViewColumn *col3 = gtk_tree_view_column_new_with_attributes("Date De Naissance", renderer, "text", 2, NULL);
    GtkTreeViewColumn *col4 = gtk_tree_view_column_new_with_attributes("        Cin      ", renderer, "text", 3, NULL);
    GtkTreeViewColumn *col5 = gtk_tree_view_column_new_with_attributes("Sexe", renderer, "text", 4, NULL);

    gtk_tree_view_append_column(tree_view, col1);
    gtk_tree_view_append_column(tree_view, col2);
    gtk_tree_view_append_column(tree_view, col3);
    gtk_tree_view_append_column(tree_view, col4);
    gtk_tree_view_append_column(tree_view, col5);
	

}


// Function to update GTK+ labels with agent details
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
                          GtkWidget *parkingag) {
    // Open the file to get the CIN
    FILE *file = fopen(file_path, "r");
    if (!file) {
        g_print("Error: Could not open file %s\n", file_path);
        return;
    }

    char cinmod[10];
    fscanf(file, "%s", cinmod);
    fclose(file);

    // Fetch the agent details using the CIN
    Agent agent = {0};
    search_agent_by_cin(cinmod, &agent);

    // Update GTK+ labels
    gtk_label_set_text(GTK_LABEL(nomagent), agent.general.name);
    gtk_label_set_text(GTK_LABEL(prenomagent), agent.general.prenom);
    gtk_label_set_text(GTK_LABEL(datenaissanceagent), agent.general.date_naissance);
    gtk_label_set_text(GTK_LABEL(cinagent), agent.general.num_cin);
    gtk_label_set_text(GTK_LABEL(sexeagent), agent.general.sexe);
    gtk_label_set_text(GTK_LABEL(numsecag), agent.general.num_securite_sociale);
    gtk_label_set_text(GTK_LABEL(bacag), agent.general.bac);

    char buffer[20];
    sprintf(buffer, "%d", agent.general.annees_apres_bac);
    gtk_label_set_text(GTK_LABEL(anneapresbacag), buffer);

    sprintf(buffer, "%d", agent.general.annee_de_bac);
    gtk_label_set_text(GTK_LABEL(annebacag), buffer);

    sprintf(buffer, "%d", agent.experience.nbre_annees_experience);
    gtk_label_set_text(GTK_LABEL(anneeperience), buffer);

    gtk_label_set_text(GTK_LABEL(nomdiplomeagent), agent.experience.nom_diplome);
    gtk_label_set_text(GTK_LABEL(armeeagent), agent.experience.armee);
    gtk_label_set_text(GTK_LABEL(numtlfnagents), agent.contact.num_telephone);
    gtk_label_set_text(GTK_LABEL(emilagent), agent.contact.email);
    gtk_label_set_text(GTK_LABEL(nomurg), agent.contact.nom_contact_urgence);
    gtk_label_set_text(GTK_LABEL(numurg), agent.contact.num_contact);

    gtk_label_set_text(GTK_LABEL(pneu), (agent.services.control_pneus == 1) ? "Oui" : "Non");
    gtk_label_set_text(GTK_LABEL(mechanique), (agent.services.check_mecanique == 1) ? "Oui" : "Non");
    gtk_label_set_text(GTK_LABEL(couvrir), (agent.services.couvrir_voiture == 1) ? "Oui" : "Non");
    gtk_label_set_text(GTK_LABEL(vidange), (agent.services.vidange == 1) ? "Oui" : "Non");
    gtk_label_set_text(GTK_LABEL(carburant), (agent.services.remplir_carburant == 1) ? "Oui" : "Non");
    gtk_label_set_text(GTK_LABEL(voiturier), (agent.services.voiturier == 1) ? "Oui" : "Non");

    gtk_label_set_text(GTK_LABEL(cinpathtext), agent.documents.cin_path);
    gtk_label_set_text(GTK_LABEL(b3path), agent.documents.b3_path);
    gtk_label_set_text(GTK_LABEL(diplomepath), agent.documents.diplome_path);
    gtk_label_set_text(GTK_LABEL(photopath), agent.documents.photo_path);

    gtk_label_set_text(GTK_LABEL(travaillernuit), agent.work_info.travaille_nuit);

    sprintf(buffer, "%d", agent.work_info.heures_par_semaine);
    gtk_label_set_text(GTK_LABEL(nbrheure), buffer);

    char price_buffer[20], salary_buffer[20];
    sprintf(price_buffer, "%f", agent.work_info.prix_heure);
    sprintf(salary_buffer, "%f", agent.work_info.salaire);

    gtk_label_set_text(GTK_LABEL(prixheure), price_buffer);
    gtk_label_set_text(GTK_LABEL(salaireag), salary_buffer);
    gtk_label_set_text(GTK_LABEL(parkingag), agent.work_info.parking);
}
int count_lines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1; // Return -1 to indicate an error
    }

    int lines = 0;
    char ch;

    // Loop through each character in the file
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
    }

    fclose(file);
    return lines;
}
void update_count_labels(GtkWidget *nbrparking, GtkWidget *nbragents, GtkWidget *nbrdesreservation) {
    // Files to count lines from
    const char *parking_file = "parking.txt";
    const char *agents_file = "agent.txt";
    const char *reservation_file = "reservation.txt";

    // Count lines in each file
    int np = count_lines(parking_file);
    int na = count_lines(agents_file);
    int nr = count_lines(reservation_file);

    // Temporary buffers to hold the string representations
    char npc[10], nac[10], nrc[10];

    // Convert counts to strings
    sprintf(npc, "%d", np);
    sprintf(nac, "%d", na);
    sprintf(nrc, "%d", nr);

    // Update the labels
    gtk_label_set_text(GTK_LABEL(nbrparking), npc);
    gtk_label_set_text(GTK_LABEL(nbragents), nac);
    gtk_label_set_text(GTK_LABEL(nbrdesreservation), nrc);
}



// Smooth interpolation without any math functions
double custom_smooth_interpolate(double t) {
    // Quadratic ease in-out approximation using only basic math
    if (t < 0.5) {
        return 5.0 * t * t;
    } else {
        double inv_t = 1.0 - t;
        return 1.0 - (2.0 * inv_t * inv_t);
    }
}

gboolean smooth_nod_callback(gpointer data) {
    SmoothNodData *nod_data = (SmoothNodData *)data;
    
    // Safety check
    if (!GTK_IS_WINDOW(nod_data->window)) {
        g_free(nod_data);
        return G_SOURCE_REMOVE;
    }

    // Normalize progress
    double progress = (double)nod_data->step / nod_data->total_steps;
    
    // Use custom interpolation for smoother movement
    double interpolated_progress = custom_smooth_interpolate(progress);
    
    // Calculate offset with improved smoothness
    int offset = (int)(interpolated_progress * nod_data->max_offset);
    
    // Alternate direction of shake
    if (nod_data->step > nod_data->total_steps / 2) {
        offset = -offset;
    }
    
    // Move window
    int new_x = nod_data->original_x + offset;
    
    gtk_window_move(nod_data->window, new_x, nod_data->original_y);

    nod_data->step++;

    // End animation
    if (nod_data->step > nod_data->total_steps) {
        gtk_window_move(nod_data->window, nod_data->original_x, nod_data->original_y);
        g_free(nod_data);
        return G_SOURCE_REMOVE;
    }

    return G_SOURCE_CONTINUE;
}

void smooth_nod_window(GtkWindow *window) {
    // Safety checks
    if (!GTK_IS_WINDOW(window)) {
        g_warning("Attempted to shake an invalid window");
        return;
    }

    SmoothNodData *nod_data = g_new(SmoothNodData, 1);
    
    // Ensure window is realized
    gtk_widget_realize(GTK_WIDGET(window));
    
    // Get original window position
    gtk_window_get_position(window, &nod_data->original_x, &nod_data->original_y);
    
    nod_data->window = window;
    nod_data->step = 0;
    nod_data->max_offset = 15;  // Shake intensity
    nod_data->total_steps = 15; // Animation steps
    
    // Start animation
    g_timeout_add(13, smooth_nod_callback, nod_data);
}
void filterReservationsByDate(const char* inputFilename, const char* outputFilename, int day, int month, int year) {
    FILE *inputFile = fopen(inputFilename, "r");
    FILE *outputFile = fopen(outputFilename, "w");

    if (inputFile == NULL) {
        perror("Error opening input file");
        return;
    }

    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return;
    }

    Reservation res;
    while (fscanf(inputFile, "%d %d %s %s %s %d %d %d %d %d %d %d %d %d %d",
                  &res.id_res, &res.cin, res.nom, res.city, res.gouvernorat,
                  &res.jour, &res.mois, &res.annee, &res.heuredebut, &res.minutedebut,
                  &res.heurefin, &res.minutefin, &res.sexe, &res.retard[0], &res.retard[1]) == 15) {

        if (res.jour == day && res.mois == month && res.annee == year) {
            fprintf(outputFile, "%d %d %s %s %s %d %d %d %d %d %d %d %d %d %d\n",
                    res.id_res, res.cin, res.nom, res.city, res.gouvernorat,
                    res.jour, res.mois, res.annee, res.heuredebut, res.minutedebut,
                    res.heurefin, res.minutefin, res.sexe, res.retard[0], res.retard[1]);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}
void populate_treeview_from_file(GtkTreeView *treeview, const char *filename) {
    GtkListStore *list_store;
    GtkTreeIter iter;
    FILE *file;
    Reservation res;

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Create a list store with the appropriate columns
    list_store = gtk_list_store_new(15, 
        G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, 
        G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, 
        G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);

    // Read reservations from file and add them to the list store
    while (fscanf(file, "%d %d %s %s %s %d %d %d %d %d %d %d %d %d %d",
                  &res.id_res, &res.cin, res.nom, res.city, res.gouvernorat,
                  &res.jour, &res.mois, &res.annee, &res.heuredebut, &res.minutedebut,
                  &res.heurefin, &res.minutefin, &res.sexe, &res.retard[0], &res.retard[1]) == 15) {
        gtk_list_store_append(list_store, &iter);
        gtk_list_store_set(list_store, &iter,
                           0, res.id_res,
                           1, res.cin,
                           2, res.nom,
                           3, res.city,
                           4, res.gouvernorat,
                           5, res.jour,
                           6, res.mois,
                           7, res.annee,
                           8, res.heuredebut,
                           9, res.minutedebut,
                           10, res.heurefin,
                           11, res.minutefin,
                           12, res.sexe,
                           13, res.retard[0],
                           14, res.retard[1],
                           -1);
    }

    fclose(file);

    // Set the list store as the model for the tree view
    gtk_tree_view_set_model(treeview, GTK_TREE_MODEL(list_store));

    // Unreference the list store (the tree view will hold its own reference)
    g_object_unref(list_store);
}

void setup_treeview_columns(GtkTreeView *treeview) {
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    const char *column_titles[] = {
        "ID Res", "CIN", "Name", "City", "Governorate",
        "Day", "Month", "Year", "Start Hour", "Start Minute",
        "End Hour", "End Minute", "Sex", "Delay 1", "Delay 2"
    };

    // Add columns to the tree view
    for (int i = 0; i < 15; i++) {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(column_titles[i], renderer, "text", i, NULL);
        gtk_tree_view_append_column(treeview, column);
    }
}


int validate_login_from_file(const char *usr, const char *pwd) {
    FILE *file = fopen("logsf.txt", "r");
    if (!file) {
        g_warning("Could not open login_info.txt");
        return 0;  // File couldn't be opened
    }

    char line[100];
    login file_login;

    // Read each line and split by space
    while (fgets(line, sizeof(line), file)) {
        // Remove trailing newline, if any
        line[strcspn(line, "\n")] = 0;

        // Split the line into username and password
        if (sscanf(line, "%s %s", file_login.username, file_login.password) == 2) {
            if (strcmp(usr, file_login.username) == 0 && strcmp(pwd, file_login.password) == 0) {
                fclose(file);
                return 1;  // Credentials matched
            }
        }
    }

    fclose(file);
    return 0;  // No matching credentials found
}
void send_email() {
    system("echo 'Your new password is 14437272' | mail -s 'Password Reset' mohreb3@gmail.com");
}
