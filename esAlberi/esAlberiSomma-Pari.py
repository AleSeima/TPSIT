#attraversare l'albero prima tutte sinistra poi destra


class Node:
    def __init__(self,data):    #costruttore, self = se stesso solo nella definizione e non nella chiamata
        self.left=None
        self.right=None
        self.data=data
    def insert(self,data):  
    #confonta il valore del nodo da aggiungere con il nodo corrente
        if self.data:   #per vedere se esiste
            if data<self.data:  #se il dato corrente è minore del dato precedente se 3 < 12
                if self.left is None:   #se il valore esiste o meno
                    self.left=Node(data)    #se è nullo lo crea
                else:
                    self.left.insert(data)  #se esiste va avanti con la ricerca
            elif data>self.data:    #se il dato corrente è maggiore del dato precedente
                if self.right is None:
                    self.right=Node(data)
                else:
                    self.right.insert(data)
        else:
            self.data=data

    #stampa albero
    def PrintTree(self):
        if self.left:
            self.left.PrintTree()   #stampa sinistra
        print(self.data)    #stampa centro
        if self.right:
            self.right.PrintTree()  #stampa destra

    def PreorderTraversal(self, root):
        res = []
        if root:
            res.append(root.data)
            res = res + self.PreorderTraversal(root.left)
            res = res + self.PreorderTraversal(root.right)
        return res

    def PostorderTraversal(self, root):
        res = []
        if root:
            res = self.PostorderTraversal(root.left)
            res = res + self.PostorderTraversal(root.right)
            res.append(root.data)
        return res

    def inorderTraversal(self,root):
        res=[]
        if root:
            res = self.inorderTraversal(root.left)
            res.append(root.data)
            res = res+self.inorderTraversal(root.right)
        return res

    def sumNode(self):
        somma = 0
        listaApp = root.inorderTraversal(self) #lettura dei valori dell'albero tramite la funzione inorder traversal
        for num in listaApp:    #aggiornamento della somma seguendo la lista di valori ricavata
            somma += num     #incremento variabile
        return somma

    def evenList(self):
        listaPari = []

        listaApp = root.inorderTraversal(self) #lettura dei valori dell'albero tramite la funzione inorder traversal
        for numero in listaApp:    #aggiornamento della lista pari seguendo la lista di valori ricavata
            if numero % 2 == 0:
                listaPari.append(numero)        #aggiunge alla lista di pari il numero pari

        return listaPari

#metodo di inserimento per aggiungere i nodi
root=Node(27)   #per creareil dopo radice, quello principale
root.insert(14)
root.insert(35)
root.insert(10)
root.insert(19)
root.insert(31)
root.insert(42)
print("Elementi albero:")
root.PrintTree()
somma = root.sumNode()
print(f"Somma:  {somma}")
listaPari = root.evenList()
print(f"SNumeri pari:  {listaPari}")