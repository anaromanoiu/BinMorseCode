#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct BinaryTreeN {
    char data; //for English alphabet
    char morse_code[1024]; //for Morse Code

    struct BinaryTreeN *left;
    struct BinaryTreeN *right;
} BinaryTreeNode;


typedef struct BinaryTreeR {
    struct BinaryTreeN *pRootNode;
} BinaryTree;


BinaryTree *CreateTree(BinaryTreeNode RootNode); //will make a binary tree and return it

BinaryTreeNode *InsertLeftChild(BinaryTreeNode *pParent, BinaryTreeNode element); //will insert the left child node of the respective node

BinaryTreeNode *InsertRightChild(BinaryTreeNode *pParent, BinaryTreeNode value);  //will insert the right child node of the respective node

BinaryTreeNode *GetRootNode(BinaryTree *pBinaryTree);  //will return the root node of the respective binary tree

//BinaryTreeNode *GetLeftChild(BinaryTreeNode *pNode); //will return the left child node of the respective node
//BinaryTreeNode *GetRightChild(BinaryTreeNode *pNode); //will return the right child node of the respective node

void DeleteTree(BinaryTree *pTree); //will delete the respective binary tree

void DeleteTreeNode(BinaryTreeNode *pnode); //recursive function to delete a binary tree

BinaryTree *CreateMorseCode(); //will create a binary tree for Morse Code with A-Z

void AssignMorseCode(BinaryTree *CodeTree); //will assign Morse Code to each alphabet, by calling a recursive function

void AssignMorseCodeRecursive(BinaryTreeNode *pParent, BinaryTreeNode *pNode, char x); //a recursive function to assign Morse Code to each alphabet

void searchMorseCodeFromWordRecursive(BinaryTreeNode *pRoot, char word);  //a recursive function to search and print the Morse Code of each alphabet

void SearchWordFromMorseCode(BinaryTree *pTree, char *morseCode); //will search the Morse Code of each alphabet, by calling a recursive function

void PrintMorseCodeFromWord(BinaryTree *CodeTree, char *word); //will print the Morse Code of the input word

void PrintWordFromMorseCode(BinaryTree *morseCodeTree, char *morsecode);  //will print the word of the input Morse Code

void SearchWordFromMorseCodeRecursive(BinaryTreeNode *pRoot, char *morsecode);   //a recursive function to search and print the alphabet of each Morse Code

void TraverseTreeNode(BinaryTreeNode *node, int level, char type); //will print all the data (alphabet+Morse Code) of a tree, by calling a recursive function

void TraverseTree(BinaryTree *tree);  //a recursive function to print a tree

void SearchMorseCodeFromWord(BinaryTree *pTree, char morseCode);

BinaryTree *CreateTree(BinaryTreeNode RootNode) {

    BinaryTree *pReturn = NULL;    //a binary tree to return
    pReturn = (BinaryTree *) malloc(sizeof(BinaryTree)); //allocating memory
    if (pReturn != NULL) {
        pReturn->pRootNode = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
        if (pReturn->pRootNode != NULL) {
            *(pReturn->pRootNode) = RootNode;
            pReturn->pRootNode->left = NULL;
            pReturn->pRootNode->right = NULL;
        } else
            printf("Error!\n");
    } else
        printf("Error\n");
    return pReturn; //return the tree
}

BinaryTreeNode *InsertLeftChild(BinaryTreeNode *pParent, BinaryTreeNode element) {
    BinaryTreeNode *pReturn = NULL;  //a node to return
    if (pParent != NULL) {
        if (pParent->left == NULL) {
            pParent->left = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode)); //allocating memory
            if (pParent->left != NULL) {
                *(pParent->left) = element; //set the element as the left child node
                pParent->left->left = NULL;
                pParent->left->right = NULL;
                pReturn = pParent->left; //setting the current left node to be returned
            } else
                printf("Error!\n");
        } else
            printf("The node exists\n");
    }
    return pReturn;
}

BinaryTreeNode *InsertRightChild(BinaryTreeNode *pParent, BinaryTreeNode value) {
    BinaryTreeNode *pReturn = NULL;
    if (pParent != NULL) {
        if (pParent->right == NULL) {
            pParent->right = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
            if (pParent->right != NULL) {
                *(pParent->right) = value;
                pParent->right->left = NULL;
                pParent->right->right = NULL;
                pReturn = pParent->right;
            } else
                printf("Error!\n");
        } else
            printf("The node exists\n");
    }
    return pReturn;
}

BinaryTreeNode *GetRootNode(BinaryTree *pBinaryTree) {
    BinaryTreeNode *pReturn = NULL;
    if (pBinaryTree != NULL)
        pReturn = pBinaryTree->pRootNode; //setting the root node as a node to return
    return pReturn;
}


//BinaryTreeNode *GetLeftChild(BinaryTreeNode *pNode) {
//    BinaryTreeNode *pReturn = NULL;
//    if (pNode != NULL)
//        pReturn = pNode->left;
//    return pReturn;
//}

//BinaryTreeNode *GetRightChild(BinaryTreeNode *pNode) {
//    BinaryTreeNode *pReturn = NULL;
//    if (pNode != NULL)
//        pReturn = pNode->right;
//    return pReturn;
//}

void DeleteTree(BinaryTree *pTree) {
    if (pTree != NULL) {
        DeleteTreeNode(pTree->pRootNode); //since we have to delete all the  nodes under the root node, the recursive function is needed to be called
        free(pTree);
    }
}


void DeleteTreeNode(BinaryTreeNode *pNode) {
    if (pNode != NULL) {
        DeleteTreeNode(pNode->left); //recursive call for all left child nodes
        DeleteTreeNode(pNode->right); //recursive call for all right child nodes
        free(pNode);
    }
}


BinaryTree *CreateMorseCode() {
    BinaryTree *pReturn = NULL; //tree to return
    //nodes for each letter
    BinaryTreeNode *pNodeA = NULL, *pNodeB = NULL, *pNodeC = NULL;
    BinaryTreeNode *pNodeD = NULL, *pNodeE = NULL, *pNodeF = NULL;
    BinaryTreeNode *pNodeG = NULL, *pNodeH = NULL, *pNodeI = NULL;
    BinaryTreeNode *pNodeJ = NULL, *pNodeK = NULL, *pNodeL = NULL;
    BinaryTreeNode *pNodeM = NULL, *pNodeN = NULL, *pNodeO = NULL;
    BinaryTreeNode *pNodeP = NULL, *pNodeQ = NULL, *pNodeR = NULL;
    BinaryTreeNode *pNodeS = NULL, *pNodeT = NULL, *pNodeU = NULL;
    BinaryTreeNode *pNodeV = NULL, *pNodeW = NULL, *pNodeX = NULL;
    BinaryTreeNode *pNodeY = NULL, *pNodeZ = NULL, *pNodeStart = NULL;

    BinaryTreeNode node = {0};
    node.data = '-'; //"-" means start
    pReturn = CreateTree(node); //make a binary tree

    if (pReturn != NULL) {
        *(node.morse_code) = *(char *) malloc(10); //allocating memory for morse code
        pNodeStart = GetRootNode(pReturn); //root node as start

        //inserting all the alphabet using the insert functions
        node.data = 'E';
        pNodeE = InsertLeftChild(pNodeStart, node);
        node.data = 'T';
        pNodeT = InsertRightChild(pNodeStart, node);

        if (pNodeE != NULL) {
            node.data = 'I';
            pNodeI = InsertLeftChild(pNodeE, node);
            node.data = 'A';
            pNodeA = InsertRightChild(pNodeE, node);
        }

        if (pNodeT != NULL) {
            node.data = 'N';
            pNodeN = InsertLeftChild(pNodeT, node);
            node.data = 'M';
            pNodeM = InsertRightChild(pNodeT, node);
        }

        if (pNodeI != NULL) {
            node.data = 'S';
            pNodeS = InsertLeftChild(pNodeI, node);
            node.data = 'U';
            pNodeU = InsertRightChild(pNodeI, node);
        }

        if (pNodeA != NULL) {
            node.data = 'R';
            pNodeR = InsertLeftChild(pNodeA, node);
            node.data = 'W';
            pNodeW = InsertRightChild(pNodeA, node);
        }

        if (pNodeN != NULL) {
            node.data = 'D';
            pNodeD = InsertLeftChild(pNodeN, node);
            node.data = 'K';
            pNodeK = InsertRightChild(pNodeN, node);
        }

        if (pNodeM != NULL) {
            node.data = 'G';
            pNodeG = InsertLeftChild(pNodeM, node);
            node.data = 'O';
            pNodeO = InsertRightChild(pNodeM, node);
        }

        if (pNodeS != NULL) {
            node.data = 'H';
            pNodeH = InsertLeftChild(pNodeS, node);
            node.data = 'V';
            pNodeV = InsertRightChild(pNodeS, node);
        }

        if (pNodeE != NULL) {
            node.data = 'I';
            pNodeI = InsertLeftChild(pNodeE, node);
            node.data = 'A';
            pNodeA = InsertRightChild(pNodeE, node);
        }

        if (pNodeU != NULL) {
            node.data = 'F';
            pNodeF = InsertLeftChild(pNodeU, node);
        }


        if (pNodeR != NULL) {
            node.data = 'L';
            pNodeL = InsertLeftChild(pNodeR, node);
        }

        if (pNodeW != NULL) {
            node.data = 'P';
            pNodeP = InsertLeftChild(pNodeW, node);
            node.data = 'J';
            pNodeJ = InsertRightChild(pNodeW, node);
        }

        if (pNodeD != NULL) {
            node.data = 'B';
            pNodeB = InsertLeftChild(pNodeD, node);
            node.data = 'X';
            pNodeX = InsertRightChild(pNodeD, node);
        }

        if (pNodeK != NULL) {
            node.data = 'C';
            pNodeC = InsertLeftChild(pNodeK, node);
            node.data = 'Y';
            pNodeY = InsertRightChild(pNodeK, node);
        }

        if (pNodeG != NULL) {
            node.data = 'Z';
            pNodeZ = InsertLeftChild(pNodeG, node);
            node.data = 'Q';
            pNodeQ = InsertRightChild(pNodeG, node);
        }
    }

    return pReturn; //return the tree
}

void AssignMorseCode(BinaryTree *CodeTree) {
    if (CodeTree != NULL) {
        AssignMorseCodeRecursive(NULL, CodeTree->pRootNode, '1'); //calls the recursive function, since the root node does not have parent, its parent node is set as NULL
    }
}

void AssignMorseCodeRecursive(BinaryTreeNode *pParent, BinaryTreeNode *pNode, char x) {
    if (pNode != NULL) {
        if (x == '1') //'1' means start == root node
            strcpy(pNode->morse_code, ""); //root node doesn't have any letter
        else {
            strcpy(pNode->morse_code, pParent->morse_code); //Copy parent node's Morse Code to the respective node's Morse Code
            if (x == 'l') // 'l' means left
                strcat(pNode->morse_code, ".");
            else if (x == 'r') //'r' means right
                strcat(pNode->morse_code, "_");
        }

        //calls recursive functions for all left and right child nodes
        AssignMorseCodeRecursive(pNode, pNode->left, 'l');
        AssignMorseCodeRecursive(pNode, pNode->right, 'r');
    }
}


void PrintMorseCodeFromWord(BinaryTree *CodeTree, char *word) {
    int i;
    char c;
    if (CodeTree != NULL && word != NULL) {
        printf("\"%s\" -> ", word);
        for (i = 0; i < strlen(word); i++) {
            c = *(word + i);
            if (c >= 'a' && c <= 'z')
                c -= 32; //letters must be uppercase, so we will change the input if it is lowercase
            if (c == ' ' || c == '\t')
                printf("[space]");
            SearchMorseCodeFromWord(CodeTree, c); //calls a function to search morse code of alphabet
        }
        printf("\n");
    }
}

void SearchMorseCodeFromWord(BinaryTree *pTree, char morseCode) {
    if (pTree != NULL && morseCode != '\0') {
        searchMorseCodeFromWordRecursive(pTree->pRootNode, morseCode); //calls the recursive function
    }
}


void searchMorseCodeFromWordRecursive(BinaryTreeNode *pRoot, char word) {
    int x = 0;
    if (pRoot != NULL && word != '\0') {
        if (pRoot->data == word) { //if found
            printf("%s", pRoot->morse_code); //return
            x = 1;
        }
        if (x == 0) { //if not found
            //continue calling the recursive function for all left and right nodes
            searchMorseCodeFromWordRecursive(pRoot->left, word);
            searchMorseCodeFromWordRecursive(pRoot->right, word);
        }
    }
}


void PrintWordFromMorseCode(BinaryTree *morseCodeTree, char *morsecode) {
    char code[1024] = "";
    char *p = NULL;
    if (morseCodeTree != NULL && morsecode != NULL) {
        strcpy(code, morsecode);
        printf("%s -> ", code);
        //the input needs to be separated by space to search the alphabet for the respective Morse Code
        p = strtok(code, " ");
        while (p != NULL) {
            SearchWordFromMorseCode(morseCodeTree, p); //calls the function to search the alphabet of Morse Code
            p = strtok(NULL, " ");
        }
        printf("\n");
    }
}

void SearchWordFromMorseCode(BinaryTree *pTree, char *morseCode) {
    if (pTree != NULL && morseCode != NULL) {
        SearchWordFromMorseCodeRecursive(pTree->pRootNode, morseCode); //calls the recursive function
    }
}

void SearchWordFromMorseCodeRecursive(BinaryTreeNode *pRoot, char *morsecode) {
    int x = 0;
    char c;
    if (pRoot != NULL && morsecode != NULL) {
        if (strcmp(pRoot->morse_code, morsecode) == 0) {
            c = pRoot->data;
            printf("%c", c);
            x = 1;
        }
        if (x == 0) {
            //continue calling the recursive function for all the left and right child nodes
            SearchWordFromMorseCodeRecursive(pRoot->left, morsecode);
            SearchWordFromMorseCodeRecursive(pRoot->right, morsecode);
        }
    }
}

void TraverseTree(BinaryTree *tree) {
    if (tree != NULL)
        TraverseTreeNode(tree->pRootNode, 0, 'O');
    else
        printf("Tree is NULL");
}

void TraverseTreeNode(BinaryTreeNode *node, int level, char type) {
    int i = 0;
    if (node != NULL) {
        printf("%c %s", node->data, node->morse_code); //print the alphabet and the Morse Code
        printf("\n");
        //continue calling the recursive function for all the left and right child nodes
        TraverseTreeNode(node->left, level + 1, 'L');
        TraverseTreeNode(node->right, level + 1, 'R');
    }
}


void remove_new_line(char *string);


int main() {
    char choice[15] = {0};
    char input[1024] = {0};
    BinaryTree *test = CreateMorseCode(); // make the Morse Code binary tree and save it
    printf("The binary tree for morse code was created. \n\n");
    AssignMorseCode(test);
    printf("Assigned the morse code to the tree \n\n");

    //loop showing options
    while (1) {
        printf("\n>>>>OPTIONS<<<<\n");
        printf(" 1. Print all\n 2. Convert english word -> morse code \n 3. Convert morse code -> english word \n 4. Exit \n");
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            printf("\n>>>Binary Tree for Morse Code: \n");
            TraverseTree(test);
        } else if (strcmp(choice, "2") == 0) {
            printf("\n Enter the english word: ");
            fflush(stdin);  //flushes the output buffer of a stream
            fgets(input, 1024, stdin); // reads a line from the specified stream and stores it into the string pointed to by str. It stops when either (n-1) characters are read, the newline character is read, or the end-of-file is reached, whichever comes first.
            remove_new_line(input);
            PrintMorseCodeFromWord(test, input);

        } else if (strcmp(choice, "3") == 0) {
            printf("\n Enter the morse code: ");
            fflush(stdin);
            fgets(input, 1024, stdin);
            remove_new_line(input);
            PrintWordFromMorseCode(test, input);

        } else if (strcmp(choice, "4") == 0) {
            printf("\nThe program is quitted.....");
            break;
        } else
            printf("\n This option cannot be recognized, \n");
    }

    DeleteTree(test);
    return 0;

}

void remove_new_line(char *string) { //to remove the new line when \n is entered in fgets input from stdin
    size_t length;
    if ((length = strlen(string)) > 0) {
        if (string[length - 1] == '\n') //if the last char index is \n
            string[length - 1] = '\0'; //change it into NULL
    }
}