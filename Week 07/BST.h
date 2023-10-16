#ifndef BST_h
#define BST_h

#include "TNode.h"
#include "Queue.h"

template <class T>
class BST {
    private:
        TNode<T>* root;

        // Tipos de recorrido
        void preorder(TNode<T>* node);
        void inorder(TNode<T>* node);
        void postorder(TNode<T>* node);
        void levelByLevel(TNode<T>* node);
        int calculateHeight(TNode<T>* node);
        bool findAncestors(TNode<T>* node, T data);
        int findLevel(TNode<T>* node, T data, int level);
    public:
        BST();
        void insert(T data);
        bool find(T data);
        void remove(T data);
        void visit(int option);
        int getHeight();
        void ancestors(T data);
        int whatLevelAmI(T data);
        int children(TNode<T>* aux);
        void print();
        bool isEmpty();
        void printTree(TNode<T>* aux, int level);
};

template <class T>
BST<T>::BST(){
    root = nullptr;
}

template <class T>
int BST<T>::children(TNode<T>* aux){
    if (aux->left != nullptr && aux->right != nullptr){
        return 2;
    } else if (aux->left != nullptr || aux->right != nullptr){
        return 1;
    }
    return 0;
}

template <class T>
void BST<T>::insert(T data){
    if(isEmpty()){
        root = new TNode<T>(data);
    } else {
        TNode<T>* aux = root;
        
        while (aux != nullptr){
            if(data < aux->data){
                if (aux->left == nullptr){
                    aux->left = new TNode<T>(data);
                    return;
                } else {
                    aux = aux->left;
                }
            } else {
                if (aux->right == nullptr){
                    aux->right = new TNode<T>(data);
                    return;
                } else {
                    aux = aux->right;
                }
            }
        }
    }
}

template <class T>
void BST<T>::remove(T data){
    // Buscar el nodo (debemo de mantener un apuntador al padre)
    TNode<T>* padre = nullptr;
    TNode<T>* aux = root;
    
    while (aux->data != data){
        padre = aux;
        data < aux->data ? aux = aux->left : aux = aux->right;
    }

    // Reviso la cantidad de hijos
    int nHijos = 0;
    nHijos = children(aux);

    // Nodo con 0 hijos
    if (nHijos == 0){
        // Nodo raíz
        if (root == aux){
            // root igual a nullptr
            root = nullptr;
            // borro el nodo
            delete aux;
        } else { // Otro nodo
            // si el nodo a borrar es menor que el padre
            if (aux < padre){
                // el apuntador del lado izquierdo del padre va a ser igual a nullptr
                padre->left = nullptr;
            } else {    // si el nodo a borrar es mayor o igual que el padre
                // el apuntador del lado derecho del padre va a ser igual a nullptr
                padre->right = nullptr;
            }
            // borro el nodo
            delete aux;
        }
    } else if (nHijos == 1){// Nodo con 1 hijo
        // Nodo raiz
        if (root == aux){
            // hacemos root igual al hijo (izquierda o derecha)
            if (aux->left != nullptr){
                root = aux->left;
            } else {
                root = aux->left;

            }
            // borro el node
            delete aux;
        } else {    // Otro nodo
            // si el nodo a borrar es menor que el padre
            if (aux < padre){
                // si el apuntador del lado izquierdo del hijo es diferente de nulo
                if (aux->left != nullptr){
                    // el apuntador del lado izquierdo del padre va ser igual al apuntador del lado izquierdo del hijo
                    padre->left = aux->left;
                } else {    // si el apuntador del lado derecho del hijo es diferente de nulo (else)
                    // el apuntador del lado izquierdo del padre va ser igual al apuntador del lado derecho del hijo
                    padre->left = aux->right;
                }
            } else {    // si el nodo a borrar es mayor o igual que el padre (else)
                // si el apuntador del lado izquierdo del hijo es diferente de nulo
                if (aux->left != nullptr){
                    // el apuntador del lado derecho del padre va ser igual al apuntador del lado izquierdo del hijo
                    padre->right = aux->left;
                } else {    // si el apuntador del lado derecho del hijo es diferente de nulo (else)
                    // el apuntador del lado derecho del padre va ser igual al apuntador del lado derecho del hijo
                    padre->right = aux->right;
                }
            }
        }
    } else {    // Nodo con 2 hijos
        // Buscamos el nodo más grande del lado izquierdo
        TNode<T>* nodoMax = aux->left;

        // El nodo del lado derecho del hijo del lado izquierdo del nodo a borrar es igual a nulo
        if (nodoMax->right == nullptr){
            // El valor del nodo a borrar va a ser igual al valor del hijo del lado izquierdo
            aux->data = nodoMax->data;
            // El apuntador del lado izquierdo del nodo a borrar es igual al apuntador del lado izquierdo del hijo
            aux->left = nodoMax->left;
            // borramos el hijo del lado izquiedo del nodo a borrar
            delete nodoMax;
        } else {    // El nodo del lado derecho del hijo del lado izquierdo del nodo a borrar no es igual a nulo (else)
            // creamos un apuntador auxiliar hijo igual al nodo del lado derecho del hijo de lado izquierdo del nodo a borrar
            TNode<T>* auxHijo = nodoMax->right;
            // creamos un apuntador auxiliar padre igual al hijo de lado izquierdo del nodo a borrar
            TNode<T>* auxPadre = nodoMax;
            // iteramos mientras el hijo del lado derecho del apuntador aux hijo no sea igual a nulos
            while (auxHijo->right != nullptr){
                // El nodo auxiliar padre va a ser igual al nodo auxiliar hijo
                auxPadre = auxHijo;
                // El nodo auxiliar hijo va a ser igual al nodo del lado izquierdo del nodo auxiliar hijo
                auxHijo = auxHijo->left;
            }
            // El valor del nodo a borrar va a ser igual al valor del apountdaor auxiliar hijo
            aux->data = auxHijo->data;
            // El apuntador del lado derecho del apuntador auxiliar padre va a ser igual al apuntador del lado izquiero del apuntador auxiliar hijo
            auxPadre->right = auxHijo->left;
            // Borramos el apuntador auxiliar hijo
            delete auxHijo;
        }
    }
}   

template <class T>
bool BST<T>::find(T data){
    TNode<T>* aux = root;

    while (aux != nullptr){
        if (data == aux->data){
            return true;
        } else {
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }  
    return false;
}

//---------------- Tipos de recorrido -----------------
template <class T>
void BST<T>::preorder(TNode<T>* node) {
    if (node) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

template <class T>
void BST<T>::inorder(TNode<T>* node) {
    if (node) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

template <class T>
void BST<T>::postorder(TNode<T>* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

template <class T>
void BST<T>::levelByLevel(TNode<T>* node) {
    if (!node)
        return;

    Queue<TNode<T>*> q;
    q.push(node);
    
    while (!q.isEmpty()) {
        TNode<T>* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
}

//----------------------------------------------------

template <class T>
void BST<T>::visit(int option){
    switch (option) {
        case 1: // Preorder
            preorder(root);
            break;
        case 2: // Inorder
            inorder(root);
            break;
        case 3: // Postorder
            postorder(root);
            break;
        case 4: // Level by level
            levelByLevel(root);
            break;
        default:
            std::cout << "Opción no válida." << std::endl;
    }    
}

//----------------------------------------------------

template <class T>
int BST<T>::calculateHeight(TNode<T>* node) {
    if (!node) {
        return 0;
    }
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    return 1 + max(leftHeight, rightHeight);
}

template <class T>
int BST<T>::getHeight(){
    return calculateHeight(root);
}

//----------------------------------------------------

template <class T>
bool BST<T>::findAncestors(TNode<T>* node, T data){
    if (node == nullptr) {
        return false;
    }

    // Si se encuentra el dato, no hay más ancestros para mostrar
    if (node->data == data) {
        return true;
    }

    // Busca en el subárbol izquierdo
    if (findAncestors(node->left, data) || findAncestors(node->right, data)) {
        // Muestra el dato actual como ancestro
        cout << node->data << " ";
        return true;
    }

    return false;
}

template <class T>
void BST<T>::ancestors(T data){
    findAncestors(root, data);
}

//----------------------------------------------------

// Método para encontrar el nivel de un dato en el BST
template <class T>
int BST<T>::findLevel(TNode<T>* node, T data, int level){    
    if (node == nullptr) {
        return -1; // Dato no encontrado
    }

    if (node->data == data) {
        return level; // Hemos encontrado el dato en este nivel
    }

    // Buscamos en los subárboles izquierdo y derecho
    int leftLevel = findLevel(node->left, data, level + 1);
    if (leftLevel != -1) {
        return leftLevel; // Se encontró en el subárbol izquierdo
    }

    int rightLevel = findLevel(node->right, data, level + 1);
    return rightLevel; // Se encontró en el subárbol derecho (o -1 si no se encontró en ambos subárboles)
}

template <class T>
int BST<T>::whatLevelAmI(T data){
    return findLevel(root,data,0);
}

//----------------------------------------------------

template<class T>
void BST<T>::printTree(TNode<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right,level+1);
        for (int i=0;i<level;i++) {
            cout << "  ";
        }
        cout << aux->data << endl;
        printTree(aux->left,level+1);
    }
}

template<class T>
void BST<T>::print() {
    if (!isEmpty()) {
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    } else {
        cout << endl << "The BST is empty" << endl << endl;
    }
} 

template <class T>
bool BST<T>::isEmpty(){
    return root == nullptr;
}


#endif