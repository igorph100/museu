#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//NÚMERO DO VISITANTE
int num_visitante = 0;


//VARIAVEIS DO SISTEMA DE ADM
int resp_menu;
void menu_adm();
void sys_obras();

//VARIAVEIS DO SISTEMA DE VENDA DE INGRESSO
int i = 0;
int opcao;
int opt_obra = 0;
char nome_obra[40] = "INVALIDO";
char tipo_ingresso[10] = "INVALIDO";
int qtd_ingresso = 50;
char cod_ingresso[9];
char ingressos[9]; // Cada string pode ter até 8 caracteres + o caractere nulo

int meia_arte,meia_dumont,meia_paris,meia_ra = 0;
int inteira_arte,inteira_dumont,inteira_paris,inteira_ra = 0;
int isencao_arte,isencao_dumont,isencao_paris,isencao_ra = 0;

//VARIAVEIS DO SISTEMA DE OBRAS DE ARTE E QUIZ
int res1, res2, res3 = 0;
char visitante[20];
char q1[20] = "NULO";
char q2[20] = "NULO";
char q3[20] = "NULO";

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    login_adm();

    return 0;
}

//FUNÇÃO DE LOGIN
void login_adm(){

    char login[5];
    char senha[5];
    char loginAdm[] = "adm";
    char senhaAdm[] = "adm";

    system("cls");
    printf("Login: ");
    scanf("%s", login);
    printf("Senha: ");
    scanf("%s", senha);

    if (strcmp(login, loginAdm) == 0 && strcmp(senha, senhaAdm) == 0)
    {
        //LOGIN SUCESSO
        menu_adm();
    }
    else
    {
        //FALHA NO LOGIN
        system("cls"); //Limpa a tela
        printf ("\nCredenciais incorretas\n\n\n");
        system("pause");
        login_adm();
    }
}
// MENU ADMINISTRADOR
void menu_adm()
{

    system("cls"); //Limpa a tela
    printf ("\nQual sistema deseja entrar ? \n\n");
    printf ("1 - Venda de ingresso.\n");
    printf ("2 - Validacao de ingresso.\n");
    printf ("3 - Obras de arte.\n\n");
    scanf("%d", &resp_menu);

    switch(resp_menu)
    {
    case 1:
        //printf ("\n venda\n");
        system("cls");
        menu_ingressos_obras();
        //verifica_quantidade();
        break;
    case 2:
        system("cls");
        printf ("\n Sistema de validação de ingressos em construção\n\n\n");
        system("pause");
        menu_adm();
        break;
    case 3:
        //printf ("\n arte\n");
        sys_obras();
        break;
    default:
        menu_adm();
        //exit(0);
    }
}
//MENU DE INGRESSOS DAS OBRAS
void menu_ingressos_obras()
{

    system("cls"); //Limpa a tela
    //opt_obra = 0;

    printf ("\nDeseja comprar ingresso para qual obra ? \n\n");
    printf ("1 - 100 anos de arte moderna.\n");
    printf ("2 - 150 anos de Santos Dumont.\n");
    printf ("3 - Jogos olimpicos de Paris 2024.\n");
    printf ("4 - Realidade virtual e aumentada.\n\n");
    scanf("%d", &resp_menu);



    switch(resp_menu)
    {
    case 1:
        //printf ("100 anos de arte moderna.\n");
        opt_obra = 1;
        strcpy(nome_obra,"100 anos de arte moderna");
        verifica_quantidade();

        break;
    case 2:
        //printf ("150 anos de Santos Dumont.\n");
        opt_obra = 2;
        strcpy(nome_obra,"150 anos de Santos Dumont");
        verifica_quantidade();

        break;
    case 3:
        //printf ("Jogos olimpicos de Paris 2024.\n");
        opt_obra = 3;
        strcpy(nome_obra,"Jogos olímpicos de Paris 2024");
        verifica_quantidade();

        break;
    case 4:
        //Realidade virtual
        opt_obra = 4;
        strcpy(nome_obra,"Realidade virtual");
        verifica_quantidade();

        break;
    case 404:
        //Codigo secreto
        //grava no arquivo


        break;
    default:
        //sys_obras();
        break;
        //exit(0);
    }
}
//FUNÇÃO SISTEMA DE OBRA DE ARTE
void sys_obras()
{

    system("cls"); //Limpa a tela
    printf ("\nQuer saber mais sobre qual evento ? \n\n");
    printf ("1 - 100 anos de arte moderna.\n");
    printf ("2 - 150 anos de Santos Dumont.\n");
    printf ("3 - Jogos olimpicos de Paris 2024.\n");
    printf ("4 - Realidade virtual e aumentada.\n\n");
    scanf("%d", &resp_menu);

    switch(resp_menu)
    {
    case 1:
        //printf ("100 anos de arte moderna.\n");
        do
        {
            num_visitante++;
            system("cls");
            printf ("\nBem-vindo à exposição sobre 100 anos da arte moderna.\n\n\n");
            system("pause");

            arte_moderna();
            questoes_quiz();
            //GRAVAR AS RESPOSTAS NO ARQUIVO
            gravar_respostas_quiz();

            system("cls");
            //system("pause");
        }
        while(resp_menu != -1);


        //arte_moderna();
        break;
    case 2:
        //printf ("150 anos de Santos Dumont.\n");
        do
        {
            num_visitante++;

            system("cls");
            printf ("\nBem-vindo à exposição sobre 150 anos de Santos Dumont.\n\n\n");
            system("pause");

            dumont();
            questoes_quiz();
            //GRAVAR AS RESPOSTAS NO ARQUIVO
            gravar_respostas_quiz();

            system("cls");
            //system("pause");
        }
        while(resp_menu != -1);

        break;
    case 3:
        do
        {
            num_visitante++;

            system("cls");
            printf ("\nBem-vindo à exposição sobre os jogos olímpicos de Paris 2024.\n\n\n");
            system("pause");

            paris();
            questoes_quiz();
            //GRAVAR AS RESPOSTAS NO ARQUIVO
            gravar_respostas_quiz();

            system("cls");
            //system("pause");
        }
        while(resp_menu != -1);

        break;
    case 4:
        do
        {
            num_visitante++;

            system("cls");
            printf ("\nBem-vindo à exposição sobre Realidade virtual.\n\n\n");
            system("pause");

            realidade_virtual();
            questoes_quiz();
            //GRAVAR AS RESPOSTAS NO ARQUIVO
            gravar_respostas_quiz();

            system("cls");
            //system("pause");
        }
        while(resp_menu != -1);

        break;
    default:
        sys_obras();
        break;
        //exit(0);
    }
}
void gravar_respostas_quiz()
{
    switch(res1)
    {
    case 1:
        strcpy(q1,"RUIM");
        break;
    case 2:
        strcpy(q1,"BOM");
        break;
    case 3:
        strcpy(q1,"MUITO BOM");
        break;
    default:
        strcpy(q1,"NULO");
        break;
    }
    //
    switch(res2)
    {
    case 1:
        strcpy(q2,"RUIM");
        break;
    case 2:
        strcpy(q2,"BOM");
        break;
    case 3:
        strcpy(q2,"MUITO BOM");
        break;
    default:
        strcpy(q2,"NULO");
        break;
    }
    //
    switch(res3)
    {
    case 1:
        strcpy(q3,"BAIXA");
        break;
    case 2:
        strcpy(q3,"MEDIA");
        break;
    case 3:
        strcpy(q3,"ALTA");
        break;
    default:
        strcpy(q3,"NULO");
        break;
    }


    // Concatenando a string e o número usando sprintf
    sprintf(visitante, "Visitante %d", num_visitante);
    FILE *pont_arq;
    pont_arq = fopen("respostas_quiz.csv","a");

    if(pont_arq == NULL)
    {
        printf("Erro na abertura do arquivo");
        return 1;
    }
    else
    {
        fprintf(pont_arq,"%s ; %s ; %s ; %s\n",visitante,q1,q2,q3);

        fclose(pont_arq);
    }




}

void verifica_quantidade()
{
    if(qtd_ingresso>=1)
    {
        sys_venda();
    }
    else
    {
        system("cls");
        printf("Ingressos esgotados\n");
        system("pause");
        return 0;
    }
}
void sys_venda()
{
    system("cls");
    printf("\nOpcões de ingresso:\n");
    printf("1. Meia entrada\n");
    printf("2. Inteira\n");
    printf("3. Isencão\n");

    printf("Escolha o tipo do ingresso: ");
    scanf("%d", &opcao);
    switch(opcao)
    {
    case 1:
        system("cls");


        if(opt_obra == 1)
        {
            printf("Meia entrada - 100 anos de arte moderna\n");
            meia_arte++;

        }
        if(opt_obra == 2)
        {
            printf("Meia entrada - 150 anos de Santos dumont\n");
            meia_dumont++;
        }
        if(opt_obra == 3)
        {
            printf("Meia entrada - Jogos olimpicos de paris 2024\n");
            meia_paris++;
        }
        if(opt_obra == 4)
        {
            printf("Meia entrada - Realidade Virtual\n");
            meia_ra++;
        }
        if(opt_obra >4 || opt_obra<=0)
        {
            printf("Ingresso inválido\n");
        }

        gerador_ingressos(1);
        strcpy(tipo_ingresso,"MEIA");
        //GRAVAR
        gravar_ingressos();


        system("pause");
        qtd_ingresso--;

        menu_ingressos_obras();
        break;

    case 2:
        system("cls");

        if(opt_obra == 1)
        {
            printf("Inteira - 100 anos de arte moderna\n");
            inteira_arte++;
        }
        if(opt_obra == 2)
        {
            printf("Inteira - 150 anos de Santos dumont\n");
            inteira_dumont++;
        }
        if(opt_obra == 3)
        {
            printf("Inteira - Jogos olimpicos de paris 2024\n");
            inteira_paris++;
        }
        if(opt_obra == 4)
        {
            printf("Inteira - Realidade Virtual\n");
            inteira_ra++;
        }
        if(opt_obra >4 || opt_obra<=0)
        {
            printf("Ingresso inválido\n");
        }

        //printf("Ingresso inteiro\n");
        gerador_ingressos(1);
        strcpy(tipo_ingresso,"INTEIRA");
        //GRAVAR
        gravar_ingressos();

        system("pause");
        qtd_ingresso--;


        menu_ingressos_obras();
        break;
    case 3:
        system("cls");

        if(opt_obra == 1)
        {
            printf("Isenção - 100 anos de arte moderna\n");
            isencao_arte++;
        }
        if(opt_obra == 2)
        {
            printf("Isenção - 150 anos de Santos dumont\n");
            isencao_dumont++;
        }
        if(opt_obra == 3)
        {
            printf("Isenção - Jogos olimpicos de paris 2024\n");
            isencao_paris++;
        }
        if(opt_obra == 4)
        {
            printf("Isenção - Realidade Virtual\n");
            isencao_ra++;
        }
        if(opt_obra >4 || opt_obra<=0)
        {
            printf("Ingresso inválido\n");
        }


        //printf("Isencao de ingresso\n");
        gerador_ingressos(1);
        strcpy(tipo_ingresso,"ISENÇÃO");
        //GRAVAR
        gravar_ingressos();

        system("pause");
        qtd_ingresso--;

        menu_ingressos_obras();
        break;


    default :
        menu_ingressos_obras();
        break;
    }
}
void gerador_ingressos(int quantidade)
{
    // Inicialize o gerador de números aleatórios com uma semente diferente a cada execução
    srand(time(NULL));

    //char cod_ingresso[9]; // 8 caracteres + caractere nulo
    for (i = 0; i < quantidade; i++)
    {

        for (i = 0; i < 8; i++)
        {
            int escolha = rand() % 2; // Gere um número aleatório de 0 a 2 para escolher entre letras maiúsculas, minúsculas ou números

            switch (escolha)
            {
            case 0:
                cod_ingresso[i] = 'A' + (rand() % 26); // Letra maiúscula
                break;
            case 1:
                cod_ingresso[i] = '0' + (rand() % 10); // Número
                break;
            }
        }

        cod_ingresso[8] = '\0'; // Adicione o caractere nulo para torná-lo uma string

        printf("Codigo do ingresso: %s\n\n",cod_ingresso);
    }

}
void gravar_ingressos()
{

    FILE *pont_arq;
    pont_arq = fopen("venda_ingressos.csv","a");

    if(pont_arq == NULL)
    {
        printf("Erro na abertura do arquivo");
        return 1;
    }
    else
    {
        fprintf(pont_arq,"%s ; %s ; %s \n",cod_ingresso,tipo_ingresso,nome_obra);

        fclose(pont_arq);
    }
}

//FUNCOES DE OBRAS DE ARTE E QUIZ

void questoes_quiz()
{
    //BLOCO TEXTO
    system("cls");
    printf ("Questionário sobre o sistema.\n\n\n");
    printf("Por favor, avalie sua satisfação em relação ao Sistema de Obras de Arte, atribuindo uma pontuação de 1 a 3.\n\n\n\n");
    system("pause");


    questao1();
    questao2();
    questao3();
}

void questao1()
{
    system("cls");
    printf("Em termos de usabilidade e facilidade de navegação, como você classificaria o Sistema?\n\n");
    printf("1) Ruim\n2) Bom\n3) Muito bom\n");

    printf("\nDigite a resposta:\n");
    scanf("%d", &res1);


}

void questao2()
{
    system("cls");
    printf("Quanto à eficiência e desempenho do Sistema, qual pontuação você atribuiria?\n\n");
    printf("1) Ruim\n2) Bom\n3) Muito bom\n");


    printf("\nDigite a resposta:\n");
    scanf("%d", &res2);

}

void questao3()
{
    system("cls");
    printf("Avalie a capacidade do Sistema em transmitir conhecimentos com base na sua experiência durante a exposição:\n\n");
    printf("1) Baixa\n2) Média\n3) Alta\n");

    printf("\nDigite a resposta:\n");
    scanf("%d", &res3);

}

// BLOCOS DE TEXTO SOBRE AS OBRAS
void dumont()
{
    //BLOCO 1
    system("cls");
    printf("Sobre Santos Dumont\n\n");
    printf("Alberto Santos Dumont nasceu em 1873, em Cabangu, Minas Gerais, Brasil. Desde jovem, manifestou uma fascinação pelos céus e pela possibilidade de voar. Sua trajetória começou com experimentos em balões, mas rapidamente evoluiu para a aviação. Em 1901, conquistou o Prêmio Deutsch de la Meurthe ao contornar a Torre Eiffel a bordo do dirigível nº 6, marcando o início de sua notoriedade como aviador.\n\n");
    system("pause");

    //BLOCO 2
    system("cls");
    printf("Os Feitos Históricos em Paris\n\n");
    printf("O auge da carreira de Santos Dumont ocorreu em Paris, onde realizou conquistas históricas na aviação. Em 1906, voou o 14-Bis, completando o primeiro voo público de um avião. Seus feitos incluíram a conquista do Prêmio Archdeacon e o Prêmio Ernest Archdeacon pela primeira viagem de um avião em forma de círculo. Estas vitórias o consagraram como um dos maiores pioneiros da aviação mundial. \n\n");
    system("pause");

    //BLOCO 3
    system("cls");
    printf("Legado e Desafios Pessoais\n\n");
    printf("Apesar de suas contribuições pioneiras, Santos Dumont enfrentou desafios pessoais e uma série de reviravoltas. Sua recusa em patentear suas invenções, visando o benefício da humanidade, refletiu seu caráter generoso. No entanto, questões de saúde e o crescimento do poder militar na aviação levaram-no a se retirar do cenário público. Santos Dumont faleceu em 1932, deixando um legado duradouro como um visionário que contribuiu significativamente para a história da aviação.\n\n");
    system("pause");
}
void arte_moderna()
{
    //BLOCO 1
    system("cls");
    printf("O Pioneirismo da Semana de Arte Moderna\n\n");
    printf("A Semana de Arte Moderna, realizada em São Paulo em 1922, foi um evento revolucionário que marcou o início do Modernismo no Brasil. Durante os dias 13 a 17 de fevereiro, artistas, escritores e músicos se reuniram no Teatro Municipal para desafiar as convenções artísticas vigentes. Sob a liderança de figuras como Mário de Andrade, Oswald de Andrade, Anita Malfatti, e Heitor Villa-Lobos, a Semana foi uma celebração da liberdade criativa, introduzindo uma nova estética que rompia com as tradições acadêmicas.\n\n");
    system("pause");

    //BLOCO 2
    system("cls");
    printf("Abaporu: Um Ícone do Modernismo Brasileiro.\n\n");
    printf("'Abaporu', uma obra-prima de Tarsila do Amaral em 1928, é um marco essencial do modernismo brasileiro. A tela retrata uma figura humana estilizada, ampliada e surrealista, com cores vibrantes e formas simplificadas. Esta obra, encomendada por Oswald de Andrade, personifica o movimento antropofágico, simbolizando a absorção e transformação de influências estrangeiras pela cultura brasileira. 'Abaporu' é mais do que uma pintura; é um manifesto artístico que expressa a riqueza e a originalidade da identidade cultural brasileira.\n\n");
    system("pause");

    //BLOCO 3
    system("cls");
    printf("Impacto e Legado Duradouro da Semana de Arte Moderna\n\n");
    printf("A Semana de Arte Moderna teve um impacto duradouro na cultura brasileira. Ao desafiar as normas estéticas e introduzir ideias vanguardistas, os participantes abriram caminho para uma abordagem mais experimental e livre na produção artística. O evento é reconhecido como um marco que impulsionou o Modernismo no Brasil, influenciando gerações subsequentes de artistas, escritores e músicos. Seu legado perdura como um símbolo da busca pela originalidade e expressão autêntica na cena cultural brasileira. \n\n");
    system("pause");
}
void paris()
{
    //BLOCO 1
    system("cls");
    printf("Expectativa Sobre os Jogos Olímpicos de Paris 2024\n\n");
    printf("Os Jogos Olímpicos de Paris 2024 prometem destacar a excelência na natação, trazendo à tona a intensidade e a competitividade que caracterizam esse esporte. Os melhores nadadores do mundo se reunirão para disputar medalhas em diversas categorias, desde provas de velocidade até maratonas aquáticas. A piscina olímpica será o palco de recordes quebrados e momentos emocionantes, proporcionando aos espectadores uma experiência memorável e inspiradora. \n\n");
    system("pause");

    //BLOCO 2
    system("cls");
    printf("Basquete: Emoção nas Quadras Parisienses\n\n");
    printf("O basquete, conhecido por sua rapidez e habilidade técnica, será uma atração de destaque nos Jogos Olímpicos de Paris 2024. As equipes de todo o mundo competirão pelo pódio, exibindo jogadas espetaculares e estratégias inovadoras. Com partidas acirradas e atletas de elite demonstrando sua maestria nas quadras parisienses, o basquete promete ser um esporte cativante, capaz de unir fãs de todas as idades em torno da paixão pelo jogo. \n\n");
    system("pause");

    //BLOCO 3
    system("cls");
    printf("Estreia do Breaking Dance: Uma Nova Dimensão Olímpica\n\n");
    printf("Uma das grandes novidades em Paris 2024 será a estreia do breaking dance, uma forma de dança urbana, nos Jogos Olímpicos. Essa inclusão reflete a evolução constante do programa olímpico, abraçando a diversidade e a cultura urbana. Os dançarinos de breaking, conhecidos por sua criatividade e habilidade única, competirão em uma atmosfera vibrante, trazendo uma nova dimensão artística aos Jogos e ampliando o apelo olímpico para públicos diversos em todo o mundo. \n\n");
    system("pause");
}
void realidade_virtual()
{
    //BLOCO 1
    system("cls");
    printf("História da Realidade virtual\n\n");
    printf("A história da Realidade Virtual (RV) remonta ao século XIX, com a invenção do estereoscópio, um dispositivo que criava a ilusão de profundidade a partir de imagens bidimensionais. No entanto, foi na década de 1960 que o termo 'Realidade Virtual' foi cunhado pelo engenheiro de aviação, Thomas Furness, enquanto trabalhava na Força Aérea dos Estados Unidos. A partir daí, pesquisadores e visionários começaram a explorar a ideia de criar ambientes virtuais interativos. \n\n");
    system("pause");

    //BLOCO 2
    system("cls");
    printf("Óculos de Realidade Virtual: Uma Janela para Outro Mundo\n\n");
    printf("Os primeiros óculos de realidade virtual surgiram na década de 1960 com a criação do Sensorama por Morton Heilig. No entanto, foi nos anos 1990 que os óculos de RV começaram a ganhar destaque com o lançamento do 'Virtual Boy' pela Nintendo. Embora esse dispositivo não tenha alcançado grande sucesso, ele marcou o início do interesse do público em experiências de realidade virtual. Nos últimos anos, empresas como Oculus (adquirida pelo Facebook) e HTC têm liderado o desenvolvimento de óculos de RV mais sofisticados, proporcionando resolução mais alta, rastreamento preciso e maior imersão. \n\n");
    system("pause");

    //BLOCO 3
    system("cls");
    printf("Potencial Transformador da Realidade Virtual\n\n");
    printf("A história recente da Realidade Virtual é marcada por avanços significativos. O renascimento da tecnologia nas últimas décadas trouxe óculos de RV mais acessíveis, como o Oculus Rift e o HTC Vive, popularizando a experiência para consumidores e ampliando as possibilidades de aplicação. A RV não está mais limitada a jogos, expandindo-se para treinamento profissional, simulações médicas, design de produtos e até mesmo terapia. O potencial transformador da Realidade Virtual continua a se expandir à medida que novas aplicações são descobertas e a tecnologia evolui, consolidando seu papel como uma ferramenta revolucionária em diversos setores. \n\n");
    system("pause");
}
