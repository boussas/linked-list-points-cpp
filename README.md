# Linked List of Points in C++

A C++ project implementing a **linked list of 2D points** with full support for:

- Adding points
- Deleting points
- Modifying points
- Displaying individual points
- Displaying all points
- Handling errors for non-existent points and empty lists

---

## 🛠 Features

- **Custom Exceptions**: `ErreurPointInexistant` and `ErreurListeVide`
- **Dynamic Memory Management**: Proper use of `new` and `delete`
- **Linked List Implementation**: Each node (`NoeudListePoints`) holds a `Point`
- **Console Output**: Visual feedback for operations

---

## 📂 Project Structure

```

linked-list-points-cpp/
│
├── main.cpp              # Main program demonstrating the list operations
└── README.md

````

---

## ⚡ Example Usage

```cpp
ListeDesPoints listePoints;

listePoints.ajouterPoint(new Point(1, 2));
listePoints.ajouterPoint(new Point(3, 4));
listePoints.visualiserPoint(1, 2);
listePoints.modifierPoint(1, 2, 10, 20);
listePoints.supprimerPoint(3, 4);
listePoints.afficherTousPoints();
````

### ✅ Output Example

```
Point (1, 2) cree avec succes.
Point (3, 4) cree avec succes.
Point aux coordonnees (1, 2) est affiche.
Point(1, 2) modifie aux nouvelles coordonnees (10, 20).
Point aux coordonnees (3, 4) supprime avec succes.
Liste des points :
(10, 20)
```

---

## 📌 Error Handling

* **Non-existent Point**: `ErreurPointInexistant`
* **Empty List**: `ErreurListeVide`

All exceptions display descriptive error messages.

---

## 🔧 How to Compile and Run

```bash
g++ main.cpp -o points
./points
```

