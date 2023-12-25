#include <iostream>
using namespace std;

class ErreurPointInexistant {
public:
    void affiche(){ cerr << "Erreur: Le point avec les coordonnees specifiees n'existe pas dans la liste." << endl; }
};


class ErreurListeVide {
public:
    void affiche(){ cerr << "Erreur: La liste est vide." << endl; }
};


class Point {
public:
    int x, y;
    Point(int a, int b) {
        x = a;
        y = b;
        cout << "Point (" << x << ", " << y << ") cree avec succes." << endl;
    }
};


class NoeudListePoints {
public:
    Point* point;
    NoeudListePoints* suivant;

    NoeudListePoints(Point* p) {
        point = p;
        suivant = nullptr;
    }

    ~NoeudListePoints() {
        delete point;
    }
};


class ListeDesPoints {
public:
    NoeudListePoints* tete;


    ListeDesPoints() {
        tete = nullptr;
    }

    ~ListeDesPoints() {
        while (tete != nullptr) {
            NoeudListePoints* temp = tete;
            tete = tete->suivant;
            delete temp;
        }
    }

   void ajouterPoint(Point* point);
    void supprimerPoint(int x, int y);
    void visualiserPoint(int x, int y);
    void modifierPoint(int xAncien, int yAncien, int xNouveau, int yNouveau);
    void afficherTousPoints();
};

void ListeDesPoints::ajouterPoint(Point* point) {
    NoeudListePoints* nouveauNoeud = new NoeudListePoints(point);
    if (tete == nullptr) {
        tete = nouveauNoeud;
    } else {
        nouveauNoeud->suivant = tete;
        tete = nouveauNoeud;
    }
}

void ListeDesPoints::supprimerPoint(int x, int y) {
    if (tete == nullptr) throw ErreurListeVide();

    NoeudListePoints* courant = tete;
    NoeudListePoints* precedent = nullptr;

    while (courant != nullptr) {
        if (courant->point->x == x && courant->point->y == y) {
            if (precedent == nullptr) {
                tete = courant->suivant;
            } else {
                precedent->suivant = courant->suivant;
            }
            delete courant;
            cout << "Point aux coordonnees (" << x << ", " << y << ") supprime avec succes." << endl;
            return;
        }
        precedent = courant;
        courant = courant->suivant;
    }
    throw ErreurPointInexistant();
}

void ListeDesPoints::visualiserPoint(int x, int y) {
    NoeudListePoints* courant = tete;
    while (courant != nullptr) {
        if (courant->point->x == x && courant->point->y == y) {
            cout << "Point aux coordonnees (" << x << ", " << y << ") est affiche." << endl;
            return;
        }
        courant = courant->suivant;
    }
    throw ErreurPointInexistant();
}

void ListeDesPoints::modifierPoint(int xAncien, int yAncien, int xNouveau, int yNouveau) {
    NoeudListePoints* courant = tete;
    while (courant != nullptr) {
        if (courant->point->x == xAncien && courant->point->y == yAncien) {
            courant->point->x = xNouveau;
            courant->point->y = yNouveau;
            cout << "Point("<<xAncien<<", "<<yAncien<<") modifie aux nouvelles coordonnees (" << xNouveau << ", " << yNouveau << ")." << endl;
            return;
        }
        courant = courant->suivant;
    }
    throw ErreurPointInexistant();
}

void ListeDesPoints::afficherTousPoints() {
    NoeudListePoints* courant = tete;
    if (courant == nullptr) {
        cout << "La liste est vide." << endl;
        return;
    }
    cout << "Liste des points :" << endl;
    while (courant != nullptr) {

        cout << "(" << courant->point->x << ", " << courant->point->y << ")" << endl;
        courant = courant->suivant;
    }
}


int main() {
    ListeDesPoints listePoints;
    try {
        listePoints.ajouterPoint(new Point(1, 2));
        listePoints.ajouterPoint(new Point(3, 7));
        listePoints.ajouterPoint(new Point(3, 4));
        listePoints.ajouterPoint(new Point(35, 44));
        listePoints.visualiserPoint(1, 2);
        listePoints.visualiserPoint(3, 7);
        listePoints.visualiserPoint(35, 44);
        listePoints.modifierPoint(1, 2, 10, 20);
        listePoints.visualiserPoint(10, 20);
        listePoints.supprimerPoint(3 , 4);
    } catch (ErreurPointInexistant& e) {
        e.affiche();
    } catch (ErreurListeVide& e) {
        e.affiche();
    } catch (...) {
        cerr << "Une erreur inattendue est survenue." << endl;
    }

    return 0;
}
