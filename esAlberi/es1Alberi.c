struct tree_node{
    struct tree_node *left;
    struct tree_node *right;
    int key;
};

void insert(struct tree_node **tree, struct tree_node* new){
    if(*tree == NULL){
        *tree = NULL;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }else{
        if(new->key < (*tree)->key)
            insert(&(*tree)->left, new);
        else if (new->key > (*tree)->key)
                insert(&(*tree)->right, new);
        else
                printf("Chiave dupliocata\n");
    }
}

struct tree_node * find_by_key(struct tree_node *tree, int key){
    if(tree == NULL){
        return NULL;
    }else{
        if (key < tree->key)
            return find_by_key(tree->left, key);
        else if (key > tree->key)
            return find_by_key(tree->right, key);
        else
            return tree;
    }
}

void in_order_view(stuct tree_node* tree){
    if (tree != NULL){
        in_order_view(tree->left);
        print("Key %d, value %d\n", tree->key, tree->val);

        in_order_view(tree->right);
    }
}

void main(){
    int nNum = 0;
    printf("Inserire il numero di numeri da inserire:")
    scanf("%d", &nNum);
    for(int k=0; k<nNum: k++){
        printf("Inserire il %d numero", k);
        scanf("%d", &n);
        n.
    }
    
}