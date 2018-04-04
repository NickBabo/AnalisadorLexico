#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __ALGORITMO__ "teste"
#define __FIMALGORITMO__ "fimalgoritmoTOKEN"
#define __ATE__ "ate"
#define __ATRIBUICAO__ "atribuicao"
#define __PARA__ "para"
#define __FIMPARA__ "fimPara"
#define __DE__ "de"
#define __INICIO__ "inicioTOKEN"
#define __PROGRAMA__  "programa"
#define __FIMPROGRAMA__ 101
#define __PROCEDIMENTO__ 102
#define __FIMPROCEDIMENTO__ 103
#define __SE__ 104
#define __FIMSE__ 919
#define __ENQUANTO__ 106
#define __FIMENQUANTO__ 107
#define __ENTAO__  108
#define __FIMENTAO__ 109
#define __SENAO__ 110
#define __FIMSENAO__ 111
#define __BOOLEANO__ 112
#define __FACA__ 113
#define __FALSO__ 114
#define __ESCREVA__ 115

#define __INTEIRO__ 200
#define __VERDADEIRO__ 201
#define __NUMERO_POSITIVO__ 202
#define __NUMERO_NEGATIVO__ 203

#define __MENOS__ 300
#define __ADICAO__ 301
#define __DIVISAO__ 302
#define __MULTIPLICACAO__ 303
#define __MAIOR__ 304
#define __MAIORIGUAL__ 305
#define __MENORIGUAL__ 306
#define __MENOR__ 307
#define __DIFERENCIACAO__ 308
#define __OPERADOR_COMPARACAO__ 309
#define __IGUAL__ 310
#define __MOD__ "mod"
#define __EXP__ "exp"
#define __MENORMAIOR__ "MenorMaior"

#define __DELIMITADOR_PA_ABERTO__ 400
#define __DELIMITADOR_PA_FECHADO__ 401
#define __DELIMITADOR_VIRGULA__ 402
#define __DELIMITADOR_DOIS_PONTOS__ 403
#define __DELIMITADOR_PONTO_VIRGULA__ 404

#define __COMENTARIO__ 500

#define __IDENTIFICADOR__ 600

#define __ERRO__ 700



typedef struct token {
    char* nome;
    char* valor;
}TOKEN;

void readFile(char txt[]);
void writeFile(char result[], int pos);
int needValue(char aux[]);
int isNumber(char c);
int isLetter(char c);

char* getValue(char txt[],int pos);
TOKEN scanner(char txt[], int *pos);

int main(int argc, char *argv[]) {
    int pos, i, tamanho;
    
    tamanho = 800;
    pos = 0;
    char txt[tamanho];
    char found[tamanho];
    
    /* Inicializar o vetor. */
    for(i = 0; i < tamanho; i++) {
        txt[i] = '\0';
    }
    
    
    readFile(txt);
    char result[tamanho];
    strcpy(result, "");
    
    char res[tamanho];
	
    while (pos < strlen(txt)) {
        
        TOKEN token = scanner(txt, &pos);
        sprintf(res, "%d", token.nome);
        strcat(result, res);
        strcat(result, " ");
        strcpy(res, "");

        if ( token.valor != NULL ) {
            strcat(result, token.valor);
            strcat(result, " ");
        }
        
        

    }
    
    writeFile(result, strlen(result));
    
    return 0;
}

TOKEN scanner(char txt[], int *pos) {
    
    TOKEN token;
    token.nome = __ERRO__;
    token.valor = NULL;
    
    (*pos)--;
q0:(*pos)++;
    if(txt[*pos] == 'a') goto q1;
    else if(txt[*pos] == '-') goto q10;
    else if(txt[*pos] == 's') goto q11;
    else if(txt[*pos] == '+') goto q16;
    else if(txt[*pos] == '*') goto q17;
    else if(txt[*pos] == '/') goto q18;
    else if(txt[*pos] == 'mod') goto q19;
    else if(txt[*pos] == '>') goto q20;
    else if(txt[*pos] == '<') goto q22;
    else if(txt[*pos] == 'exp') goto q24;
    else if(txt[*pos] == '=') goto q25;
    else if(txt[*pos] == 'f') goto q42;
    else if(txt[*pos] == 'p') goto q91;
    else if(txt[*pos] == 'd') goto q103;
    else if(txt[*pos] == 'i') goto q113;
    else if(isNumber(txt[*pos])) goto q117;
    else if(isLetter(txt[*pos])) goto q163;
    else goto q165;
q1:(*pos)++;
    if(txt[*pos] == 'l') goto q2;
    else if (txt[*pos] == 't') goto q105;
    else if( isLetter(txt[*pos]) ) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q2:(*pos)++;
    if(txt[*pos] == 'g') goto q3;
    else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q3:(*pos)++;
	if(txt[*pos] == 'o') goto q4;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q4:(*pos)++;
	if(txt[*pos] == 'r') goto q5;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q5:(*pos)++;
	if(txt[*pos] == 'i') goto q6;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q6:(*pos)++;
	if(txt[*pos] == 't') goto q7;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q7:(*pos)++;
	if(txt[*pos] == 'm') goto q8;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q8:(*pos)++;
	if(txt[*pos] == 'o') goto q9;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q9:(*pos)++;
	token.nome = __ALGORITMO__;
	token.valor = getValue(txt,*pos);
	return token;
q10:(*pos)++;
	token.nome = __MENOS__;
    token.valor = getValue(txt, *pos);
	return token;
q11:(*pos)++;
	if(txt[*pos] == 'e') goto q12;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q12:(*pos)++;
	if(txt[*pos] == ' ') {
		token.nome = __SE__;
	    token.valor = getValue(txt, *pos);

		return token;
	}else if(txt[*pos] == 'n') goto q13;
	else if(isLetter(txt[*pos])) goto q163;
    else return token;
q13:(*pos)++;
	if(txt[*pos] == 'a') goto q14;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q14:(*pos)++;
	if(txt[*pos] == 'o')goto q15;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q15:(*pos)++;
	token.nome = __SENAO__;
    token.valor = getValue(txt, *pos);

	return token;
q16:(*pos)++;
	if(txt[*pos] == ' '){
		token.nome = __ADICAO__;
	    token.valor = getValue(txt, *pos);
		return token;
	}else if(isLetter(txt[*pos])) goto q163;
    else return token;
q17:(*pos)++;
	if(txt[*pos] == ' '){
		token.nome = __MULTIPLICACAO__;
	    token.valor = getValue(txt, *pos);

		return token;
	}else if(isLetter(txt[*pos])) goto q163;
    else return token;
q18:(*pos)++;
	if(txt[*pos] == ' '){
		token.nome = __DIVISAO__;
		return token;
	}else if(isLetter(txt[*pos])) goto q163;
    else return token;
q19:(*pos)++;
	if(txt[*pos] == ' '){
		token.nome = __MOD__;
		return token;
	}else if(isLetter(txt[*pos])) goto q163;
    else return token;
q20:(*pos)++;
	if(txt[*pos] == '=') goto q21;
    else if(txt[*pos] == ' '){
    	token.nome = __MAIOR__;
    	return token;
	}else return token;
q21: (*pos)++;
	token.nome = __MAIORIGUAL__;
	return token;
q22: (*pos)++;
    if(txt[*pos] == ' ') {
    	token.nome = __MENOR__;
    	return token;
	}else if(txt[*pos] == '=') goto q23;
	else if(txt[*pos] == '-') goto q119;
	else if(txt[*pos] == '>') goto q26;
	else if(isLetter(txt[*pos])) goto q163;
    else return token;
q23: (*pos)++;
	token.nome = __MENORIGUAL__;
	return token;
q24: (*pos)++;
	token.nome = __EXP__;
	return token;
q25: (*pos)++;
	token.nome = __IGUAL__;
	return token;
q26: (*pos)++;
	token.nome = __MENORMAIOR__;
	return token;
q30: (*pos)++;
	if(txt[*pos] == 'r') goto q70;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q42: (*pos)++;
	if(txt[*pos] == 'i') goto q43;
	else if(txt[*pos] == 'a') goto q96;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q43: (*pos)++;
	if(txt[*pos] == 'm') goto q44;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q44:(*pos)++;
	 if(txt[*pos] == 'p') goto q45;
	 else if (txt[*pos] == 'e') goto q62;
	 else if (txt[*pos] == 's') goto q72;
	 else if (txt[*pos] == 'a') goto q74;
	 else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q45:(*pos)++;
	 if(txt[*pos] == 'a') goto q30;
	 if(txt[*pos] == 'r') goto q46;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q46: (*pos)++;
	if(txt[*pos] == 'o') goto q47;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q47: (*pos)++;
	if(txt[*pos] == 'g') goto q48;
	else if(txt[*pos] == 'c') goto q53;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q48: (*pos)++;
	if(txt[*pos] == 'r') goto q49;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q49: (*pos)++;
	if(txt[*pos] == 'a') goto q50;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q50: (*pos)++;
	if(txt[*pos] == 'm') goto q51;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q51: (*pos)++;
	if(txt[*pos] == 'a') goto q52;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q52: (*pos)++;
	token.nome = __FIMPROGRAMA__;
	return token;
q53: (*pos)++;
	if(txt[*pos] == 'e') goto q54;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q54: (*pos)++;
	if(txt[*pos] == 'd') goto q55;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q55: (*pos)++;
	if(txt[*pos] == 'i') goto q56;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q56: (*pos)++;
	if(txt[*pos] == 'm') goto q57;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q57: (*pos)++;
	if(txt[*pos] == 'e') goto q58;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q58: (*pos)++;
	if(txt[*pos] == 'n') goto q59;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q59: (*pos)++;
	if(txt[*pos] == 't') goto q60;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q60: (*pos)++;
	if(txt[*pos] == 'o') goto q61;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q61: (*pos)++;
	token.nome = __FIMPROCEDIMENTO__;
	return token;
q62:(*pos)++;
	if(txt[*pos] == 'n') goto q63;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q63: (*pos)++;
	if(txt[*pos] == 'q') goto q64;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q64:(*pos)++; 
	if(txt[*pos] == 'u') goto q65;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q65:(*pos)++; 
	if(txt[*pos] == 'a') goto q66;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q66:(*pos)++;
	 if(txt[*pos] == 'n') goto q67;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q67:(*pos)++;
	 if(txt[*pos] == 't') goto q68;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q68:(*pos)++;
	 if(txt[*pos] == 'o') goto q69;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q69:(*pos)++;
	token.nome = __FIMENQUANTO__;
	return token;
q70: (*pos)++;
	if(txt[*pos] == 'a') goto q71;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q71: (*pos)++;
	token.nome = __FIMPARA__;
	return token;
q72:(*pos)++;
	 if(txt[*pos] == 'e') goto q73;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q73:(*pos)++; 
	token.nome = __FIMSE__;
	return token;
	
q74:(*pos)++;
	if(txt[*pos] == 'l') goto q75;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q75:(*pos)++;
	if(txt[*pos] == 'g') goto q76;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q76:(*pos)++; 
	if(txt[*pos] == 'o') goto q77;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q77:(*pos)++;
	if(txt[*pos] == 'r') goto q78;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q78:(*pos)++;
	 if(txt[*pos] == 'i') goto q79;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q79:(*pos)++;
	 if(txt[*pos] == 't') goto q80;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q80:(*pos)++;
	 if(txt[*pos] == 'm') goto q81;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q81:(*pos)++;
	 if(txt[*pos] == 'o') goto q82;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q82:(*pos)++; 
	token.nome = __FIMALGORITMO__;
	return token;
q91:(*pos)++;
	if(txt[*pos] == 'a') goto q92;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q92: (*pos)++;
	if(txt[*pos] == 'r') goto q93;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q93: (*pos)++;
	if(txt[*pos] == 'a') goto q94;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q94: (*pos)++;
	token.nome = __PARA__;
	return token;
q96:(*pos)++;
	 if(txt[*pos] == 'c') goto q97;
	else if(txt[*pos] == 'l') goto q132;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q97:(*pos)++;
	 if(txt[*pos] == 'a') goto q98;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q98:(*pos)++;
	token.nome = __FACA__;
	return token;
q103: (*pos)++;
	if(txt[*pos] == 'e') goto q104;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q104: (*pos)++;
	token.nome = __DE__;
	return token;

q105:(*pos)++;
	if(txt[*pos] == 'e') goto q106;
	else if(isLetter(txt[*pos])) goto q163;
	else if(txt[*pos] == ' ') goto q164;
	else return token;
q106:(*pos)++;
	token.nome = __ATE__;
	token.valor = getValue(txt, *pos);
	return token;
q113:(*pos)++;
	if(txt[*pos] == 'n') goto q114;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q114:(*pos)++;
	if(txt[*pos] == 'i') goto q115;
	else if(txt[*pos] == 't') goto q135;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q115:(*pos)++;
	if(txt[*pos] == 'c') goto q116;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q116: (*pos)++;
	if(txt[*pos] == 'i') goto q217;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q217: (*pos)++;
	if(txt[*pos] == 'o') goto q218;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q218: (*pos)++;
	token.nome = __INICIO__;
	return token;
q117:(*pos)++;
    if(isNumber(txt[*pos])) goto q117;
    else if(txt[*pos] == ' ') goto q118;
    else return token;
q118:(*pos)++;
    token.nome = __NUMERO_POSITIVO__;
    token.valor = getValue(txt,*pos);
    return token;
q119:(*pos)++;
	token.nome = __ATRIBUICAO__;
	return token;
q135: (*pos)++;
	if(txt[*pos] == 'e') goto q136;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q136: (*pos)++;
	if(txt[*pos] == 'i') goto q137;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q137: (*pos)++;
	if(txt[*pos] == 'r') goto q138;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q138: (*pos)++;
	if(txt[*pos] == 'o') goto q139;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q139: (*pos)++;
	token.nome = __INTEIRO__;
	return token;
q132:(*pos)++;
	if(txt[*pos] == 's') goto q133;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q133:(*pos)++;
	if(txt[*pos] == 'o') goto q134;
	else if(isLetter(txt[*pos])) goto q163;
    else if(txt[*pos] == ' ') goto q164;
    else return token;
q134:(*pos)++;
	token.nome = __FALSO__;
    token.valor = getValue(txt, *pos);
	return token;
q163:(*pos)++;
    if(isLetter(txt[*pos])) goto q163;
    if( txt[*pos] == ' ') goto q164;
    else return token;
q164: (*pos)++;
    token.nome = __IDENTIFICADOR__;
    token.valor = getValue(txt, *pos);
    return token;
q165: (*pos)++;
	token.nome = __ERRO__;
	token.valor = getValue(txt, *pos);
	return token;
}

void readFile(char txt[]) {
    FILE *arquivo_entrada;
    arquivo_entrada = fopen("input.txt","r");
    char line[400];
    
    if (arquivo_entrada) {
        while (fscanf(arquivo_entrada,"%s ", line) != EOF) {
            strcat(line, " ");
            strcat(txt,line);
        }
        fclose(arquivo_entrada);
    }
}

int isNumber(char c) {
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
        return 1;
    return 0;
}



char* getValue(char txt[],int pos) {
   
    char *valor;
    int i,j;
    int count;
    count = 0;
    
    for (i = pos - 2 ; txt[i] != ' ' && i >= 0 ; i--) {
        count++;
    }

    valor = malloc( 2*count * sizeof(char));
    j =0;
    
    for (i = pos - 2; txt[i] != ' ' && i >= 0; i--) {
        valor[j] = txt[i - count + 1 + 2*j];
        j++;
        valor[j] = '\0';	

    }
    
    printf("Palavra Lida: %s\n",valor); 
    return valor;
}

/* Verifica se o parametro e um caractere valido na tabela ascii
   [a-z] = [97-122] e [A-Z] = [65-90] */
int isLetter(char c) {
    int a = (int) c;
    if ((a > 96 && a < 123) || (a > 64 && a < 91)) {
        return 1;
    }
    
    return 0;
}

void writeFile(char result[], int pos){
    int i,j,k;
    j = 0;
    char aux[100];
    for(i = 0 ; i< pos ; i++){
        aux[j] = result[i];
        j++;
        if (result[i] == ' ') {
            if (needValue(aux)){
                for(k = i+1 ; result[k] != ' '; k++) i++;
                i++;
            }
            result[i] = '\n';
            j = 0;
            aux[0] = '\0';
        }
    }
    FILE *file;
    file = fopen("output.txt", "w+");
    fprintf(file, result);
    fclose(file);
}

int needValue(char aux[]){
    int c;
    c = atoi(aux);
    printf("%d", c);
    if(  c == __NUMERO_POSITIVO__ || c == __NUMERO_NEGATIVO__ || c == __IDENTIFICADOR__) return  1;
    return 0;
}
