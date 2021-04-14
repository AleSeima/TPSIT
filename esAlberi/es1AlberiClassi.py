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

#metodo di inserimento per aggiungere i nodi
root=Node(12)   #per creareil dopo radice, quello principale
root.insert(6)
root.insert(14)
root.insert(3)
root.PrintTree()