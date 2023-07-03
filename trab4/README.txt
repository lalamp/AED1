Nesse trabalho, tanto para as árvores ABB e as árvores AVL temos os seguintes métodos:
        
        Os construtores BinarySearchTree() e AVLTree() que iniciam as árvores com: 
                raiz (root) = NULL;
                número de nós e de palavras distintas (num_nodes e palavras_distintas) = 0;
                        se soma um a essas variáveis a cada palavra diferente lida do texto, que também será adicionada às árvores (aumentanto o número de nós);
                número de palavras totais (palavras_total) = 0;
                        se soma um a essa variável a cada palavra lida do texto;
                as comparações entre as palavras (comparacoes) = 0;
                        se soma um a essa variável a cada comparação feita entre palavras na busca com inserção, por exemplo 'x == t->entry'
                no caso da AVL, as rotações (rotacoes) = 0;
                        se soma um a essa variável a cada rotação (LL, RR, LR, RL) feita na busca com inserção 
                e, por fim, a variável i = 1 que será utilizada no método write como contador do vetor palavras[] do tipo words (struct definida nos arquivos .h) que recebe as palavras e suas frequências.

        Métodos de busca com inserção recursiva: caso ainda não tenha sido adicionada, esse método adiciona a palavra lida do texto às árvores 
                                                caso já tenha sido adicionada, esse método soma um à frequência dessa palavra nas árvores
        void searchInsert(TreeEntry x) 
        void searchInsert(TreeEntry x, TreePointer &t) ou void searchInsert(TreeEntry x, TreePointer &pA, bool &h) 

        Métodos que retornam a altura da árvore:
        int altura();
        int altura(TreePointer &t);
        
        Métodos que retornam o número de folhas da árvore:
        int folhas();
        int folhas(TreePointer &t);
        
        Métodos para imprimir na saída as informações pedidas no trabalho:
        void write();
                Esse método, após chamar o write() recursivo, imprime na saída as respostas da tabela das letras A a J e as médias de comparações e rotações pedidas. Além disso, por meio do método de ordenação por seleção, esse método ordena em ordem crescente de frequência as palavras e, caso sejam iguais, as colocam em ordem alfabética. Após isso, para imprimir as 10 palavras com maiores frequências é feito um for que imprime os 10 últimos dados (palavras e frequências) do vetor palavras[], já que esse vetor está em ordem crescente.
        void write(TreePointer &t);
                Esse método passa os dados (palavras e suas respectivas frequências) das árvores para o vetor palavras[]