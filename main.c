#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define __NUMERO_POSITIVO__ 202
#define __NUMERO_NEGATIVO__ 203

#define __IDENTIFICADOR__ "identificador"


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

    tamanho = 8000;
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
		strcat(result, token.nome);
		strcat(result, " ");
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
    token.nome = malloc(sizeof(char) * 50);
    token.valor = NULL;

    (*pos)--;
q0:(*pos)++;
    if(txt[*pos] == 'a') {
		goto q1; //Algoritmo, Ate
	}
    else if(txt[*pos] == '-'){
		goto q10; 
	} 
    else if(txt[*pos] == 's'){
		goto q11; //Se, Senao
	} 
    else if(txt[*pos] == '+'){		
		goto q16;
	}
    else if(txt[*pos] == '*'){
		goto q17;
	} 
    else if(txt[*pos] == '/') goto q18;
    else if(txt[*pos] == 'mod') goto q19;
    else if(txt[*pos] == '>') goto q20;
    else if(txt[*pos] == '<') goto q22;
    else if(txt[*pos] == 'exp') goto q24;
    else if(txt[*pos] == '=') goto q25;
    else if(txt[*pos] == ':') goto q145;
    else if(txt[*pos] == ';') goto q146;
    else if(txt[*pos] == '(') goto q147;
    else if(txt[*pos] == ')') goto q148;
    else if(txt[*pos] == ',') goto q149;
    else if(txt[*pos] == '"') goto q161;
    else if(txt[*pos] == 'e'){
		goto q31; //Escreva, Entao, Enquanto
	}
    else if(txt[*pos] == 'l'){
		goto q38; //Leia, Logico
	}
    else if(txt[*pos] == 'f'){
		goto q42; //fimPara, fimPrograma, fimEnquanto, fimProcedimento, fimSe, fimalgoritmo, faca, falso
	} 
    else if(txt[*pos] == 'b'){
		goto q84; //booleano
	} 
    else if(txt[*pos] == 'p'){
		goto q91; //para
	} 
    else if(txt[*pos] == 'd') {
		goto q103; //De
	}
    else if(txt[*pos] == 'i'){
		goto q113; //Inicio, Inteiro
	} 
    else if(txt[*pos] == '.') goto q120;
    else if(txt[*pos] == ',') goto q121;
    else if(txt[*pos] == 'v') goto q122; //Verdadeiro
    else if(isNumber(txt[*pos])) goto q152;
    else if(isLetter(txt[*pos])) goto q29;
    else goto q165;
	
q1:(*pos)++;
    if(txt[*pos] == 'l') goto q2;
    else if (txt[*pos] == 't') goto q105;
    else if( isLetter(txt[*pos]) ) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q2:(*pos)++;
    if(txt[*pos] == 'g') goto q3;
    else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q3:(*pos)++;
	if(txt[*pos] == 'o') goto q4;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q4:(*pos)++;
	if(txt[*pos] == 'r') goto q5;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q5:(*pos)++;
	if(txt[*pos] == 'i') goto q6;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q6:(*pos)++;
	if(txt[*pos] == 't') goto q7;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q7:(*pos)++;
	if(txt[*pos] == 'm') goto q8;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83; 
    else return token;
q8:(*pos)++;
	if(txt[*pos] == 'o') goto q9;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;	 
    else return token;
q9:(*pos)++;
	if(txt[*pos] == ' ') {	
		(*pos)++;
		strcpy(token.nome, "<algoritmo>");
		return token;
	}else if(isLetter(txt[*pos])) goto q29;
q10:(*pos)++;
	if(txt[*pos] == ' ') {	
		(*pos)++;
		strcpy(token.nome, "<operadorMatematico,menos>");
		return token;
	}

q11:(*pos)++;
	if(txt[*pos] == 'e') goto q12;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;
    else return token;
q12:(*pos)++;
	if(txt[*pos] == ' ') {
		(*pos)++;
		strcpy(token.nome, "<se>");
		return token;
	}else if(txt[*pos] == 'n') goto q13;
	else if(isLetter(txt[*pos])) goto q29;
    else return token;
q13:(*pos)++;
	if(txt[*pos] == 'a') goto q14;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q14:(*pos)++;
	if(txt[*pos] == 'o')goto q15;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;
    else return token;
q15:(*pos)++;
	if(txt[*pos] == ' ') {	
		(*pos)++;
		strcpy(token.nome, "<senao>");
		return token;
	}
q16:(*pos)++;
	if(txt[*pos] == ' '){
		(*pos)++;
		strcpy(token.nome, "<operadorMatematico,adicao>");
		return token;
	}else if(isLetter(txt[*pos])) goto q29;
    else return token;
q17:(*pos)++;
	if(txt[*pos] == ' '){
		(*pos)++;
		strcpy(token.nome, "<operadorMatematico,multiplicao>");
		return token;
	}else if(isLetter(txt[*pos])) goto q29;
    else return token;
q18:(*pos)++;
	if(txt[*pos] == ' '){
		(*pos)++;
		strcpy(token.nome, "<operadorMatematico,divisao>");
		return token;
	}else if (txt[*pos] == '*') goto q154;
	else if(txt[*pos] == '/') goto q157;
	else if(isLetter(txt[*pos])) goto q29;
    else return token;
q19:(*pos)++;
	if(txt[*pos] == ' '){
		(*pos)++;
		strcpy(token.nome, "<operadorMatematico,mod>");
		return token;
	}else if(isLetter(txt[*pos])) goto q29;
    else return token;
q20:(*pos)++;
	if(txt[*pos] == '=') goto q21;
    else if(txt[*pos] == ' '){
    	(*pos)++;
    	strcpy(token.nome, "<operadorRelacional,maior>");
    	return token;
	}else return token;
q21: (*pos)++;
	if(txt[*pos] == ' '){
    	(*pos)++;
    	strcpy(token.nome, "<operadorRelacional,maiorigual>");
    	return token;
    }
	return token;
q22: (*pos)++;
    if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<operadorMatematico,menor>");
    	return token;
	}else if(txt[*pos] == '=') goto q23;
	else if(txt[*pos] == '-') goto q119;
	else if(txt[*pos] == '>') goto q26;
	else if(isLetter(txt[*pos])) goto q29;
    else return token;
q23: (*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<operadorMatematico,menorigual>");
    	return token;
	}

q24: (*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<operadorMatematico,exp>");
		return token;
	}
q25: (*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<operadorRelacional,igual>");
		return token;
	}
q26: (*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<operadorRelacional,menormaior>");
		return token;
	}
q30: (*pos)++;
	if(txt[*pos] == 'r') goto q70;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;
 
    else return token;
q31: (*pos)++;
  if(txt[*pos] == 's') goto q32;
  else if(txt[*pos] == 'n') goto q99;
  else if(isLetter(txt[*pos])) goto q29;
  else if(txt[*pos] == ' ') goto q83;
 
  else return token;
q32: (*pos)++;
  if(txt[*pos] == 'c') goto q33;
  else if(isLetter(txt[*pos])) goto q29;
  else if(txt[*pos] == ' ') goto q83;
 
  else return token;
q33: (*pos)++;
  if(txt[*pos] == 'r') goto q34;
  else if(isLetter(txt[*pos])) goto q29;
  else if(txt[*pos] == ' ') goto q83;
  else return token;
q34: (*pos)++;
  if(txt[*pos] == 'e') goto q35;
  else if(isLetter(txt[*pos])) goto q29;
  else if(txt[*pos] == ' ') goto q83;

 
  else return token;
q35: (*pos)++;
    if(txt[*pos] == 'v') goto q36;
    else if(isLetter(txt[*pos])) goto q29;
        else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q36: (*pos)++;
    if(txt[*pos] == 'a') goto q37;
    else if(isLetter(txt[*pos])) goto q29;
        else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q37: (*pos)++;
    if(txt[*pos] == 'l') goto q95;
    else if(txt[*pos] == ' ') {
		(*pos)++;
    	strcpy(token.nome, "<escreva>");
    	return token;
	}
	else if(isLetter(txt[*pos])) goto q29;
    else return token;
q38: (*pos)++;
    if(txt[*pos] == 'e') goto q39;
    else if(txt[*pos] == 'o') goto q140;
    else if(isLetter(txt[*pos])) goto q29;
        else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q39: (*pos)++;
  if(txt[*pos] == 'i') goto q40;
  else if(isLetter(txt[*pos])) goto q29;   
  else if(txt[*pos] == ' ') goto q83;


 
  else return token;
q40: (*pos)++;
  if(txt[*pos] == 'a') goto q41;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
  else return token;
q41: (*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<leia>");
		return token;
	}

q42: (*pos)++;
	if(txt[*pos] == 'i') goto q43;
	else if(txt[*pos] == 'a') goto q96;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q43: (*pos)++;
	if(txt[*pos] == 'm') goto q44;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q44:(*pos)++;
	 if(txt[*pos] == 'p') goto q45;
	 else if (txt[*pos] == 'e') goto q62;
	 else if (txt[*pos] == 's') goto q72;
	 else if (txt[*pos] == 'a') goto q74;
	 else if(isLetter(txt[*pos])) goto q29;
     else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q45:(*pos)++;
	 if(txt[*pos] == 'a') goto q30;
	 if(txt[*pos] == 'r') goto q46;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;
    else return token;
q46: (*pos)++;
	if(txt[*pos] == 'o') goto q47;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q47: (*pos)++;
	if(txt[*pos] == 'g') goto q48;
	else if(txt[*pos] == 'c') goto q53;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q48: (*pos)++;
	if(txt[*pos] == 'r') goto q49;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q49: (*pos)++;
	if(txt[*pos] == 'a') goto q50;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;
    else return token;
q50: (*pos)++;
	if(txt[*pos] == 'm') goto q51;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q51: (*pos)++;
	if(txt[*pos] == 'a') goto q52;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q52: (*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<fimPrograma>");
		return token;
	}
q53: (*pos)++;
	if(txt[*pos] == 'e') goto q54;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q54: (*pos)++;
	if(txt[*pos] == 'd') goto q55;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q55: (*pos)++;
	if(txt[*pos] == 'i') goto q56;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q56: (*pos)++;
	if(txt[*pos] == 'm') goto q57;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q57: (*pos)++;
	if(txt[*pos] == 'e') goto q58;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q58: (*pos)++;
	if(txt[*pos] == 'n') goto q59;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q59: (*pos)++;
	if(txt[*pos] == 't') goto q60;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q60: (*pos)++;
	if(txt[*pos] == 'o') goto q61;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q61: (*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<fimProcedimento>");
		return token;
	}
q62:(*pos)++;
	if(txt[*pos] == 'n') goto q63;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q63: (*pos)++;
	if(txt[*pos] == 'q') goto q64;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q64:(*pos)++;
	if(txt[*pos] == 'u') goto q65;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q65:(*pos)++;
	if(txt[*pos] == 'a') goto q66;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q66:(*pos)++;
	 if(txt[*pos] == 'n') goto q67;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q67:(*pos)++;
	 if(txt[*pos] == 't') goto q68;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q68:(*pos)++;
	 if(txt[*pos] == 'o') goto q69;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q69:(*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<fimEnquanto>");
		return token;
	}
q70: (*pos)++;
	if(txt[*pos] == 'a') goto q71;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q71: (*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<fimPara>");
		return token;
	}
q72:(*pos)++;
	 if(txt[*pos] == 'e') goto q73;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q73:(*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<fimSe>");
		return token;
	}

q74:(*pos)++;
	if(txt[*pos] == 'l') goto q75;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q75:(*pos)++;
	if(txt[*pos] == 'g') goto q76;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q76:(*pos)++;
	if(txt[*pos] == 'o') goto q77;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q77:(*pos)++;
	if(txt[*pos] == 'r') goto q78;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q78:(*pos)++;
	 if(txt[*pos] == 'i') goto q79;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q79:(*pos)++;
	 if(txt[*pos] == 't') goto q80;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q80:(*pos)++;
	 if(txt[*pos] == 'm') goto q81;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q81:(*pos)++;
	 if(txt[*pos] == 'o') goto q82;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q82:(*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<fimAlgoritmo>");
		return token;
	}
q84:(*pos)++;
  if(txt[*pos] == 'o') goto q85;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

  else return token;
q85:(*pos)++;
  if(txt[*pos] == 'o') goto q86;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

  else return token;
q86:(*pos)++;
  if(txt[*pos] == 'l') goto q87;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

  else return token;
q87:(*pos)++;
  if(txt[*pos] == 'e') goto q88;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

  else return token;
q88:(*pos)++;
  if(txt[*pos] == 'a') goto q89;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

  else return token;
q89:(*pos)++;
  if(txt[*pos] == 'n') goto q90;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

  else return token;
q90:(*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<booleano>");
		return token;
	}

q91:(*pos)++;
	if(txt[*pos] == 'a') goto q92;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q92: (*pos)++;
	if(txt[*pos] == 'r') goto q93;
	else if(txt[*pos] == 's') goto q158;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q93: (*pos)++;
	if(txt[*pos] == 'a') goto q94;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q94: (*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<para>");
		return token;
	}
q95: (*pos)++;
	if(txt[*pos] == ' ') {
		(*pos)++;
  		strcpy(token.nome, "<escreval>");
  		return token;
	}
q96:(*pos)++;
	 if(txt[*pos] == 'c') goto q97;
	else if(txt[*pos] == 'l') goto q132;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q97:(*pos)++;
	 if(txt[*pos] == 'a') goto q98;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q98:(*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<faca>");
		return token;
	}
q99:(*pos)++;
  	if(txt[*pos] == 'q') goto q107;
    else if(txt[*pos] == 't') goto q100;
  	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;
    else return token;
q100: (*pos)++;
  if(txt[*pos] == 'a') goto q101;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

  else return token;
q101: (*pos)++;
  if(txt[*pos] == 'o') goto q102;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

  else return token;
q102: (*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<entao>");
		return token;
	}
q103: (*pos)++;
	if(txt[*pos] == 'e') goto q104;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q104: (*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<de>");
		return token;
	}
q105:(*pos)++;
	if(txt[*pos] == 'e') goto q106;
	else if(isLetter(txt[*pos])) goto q29;
	else if(txt[*pos] == ' ') goto q83;
	else return token;
q106:(*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<ate>");
		return token;
	}
q107: (*pos)++;
  if(txt[*pos] == 'u') goto q108;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;
  else return token;
q108: (*pos)++;
  if(txt[*pos] == 'a') goto q109;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
  else return token;
q109: (*pos)++;
  if(txt[*pos] == 'n') goto q110;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
  else return token;
q110: (*pos)++;
    if(txt[*pos] == 't') goto q111;
    else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q111: (*pos)++;
    if(txt[*pos] == 'o') goto q112;
    else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q112: (*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<enquanto>");
		return token;
	}
q113:(*pos)++;
	if(txt[*pos] == 'n') goto q114;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

    else return token;
q114:(*pos)++;
	if(txt[*pos] == 'i') goto q115;
	else if(txt[*pos] == 't') goto q135;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q115:(*pos)++;
	if(txt[*pos] == 'c') goto q116;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q116: (*pos)++;
	if(txt[*pos] == 'i') goto q117;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q117: (*pos)++;
	if(txt[*pos] == 'o') goto q118;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q118: (*pos)++;
	if(txt[*pos] == ' '){
		(*pos)++;
		strcpy(token.nome, "<inicio>");
		return token;
	}
q119:(*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<atribuicao>");
		return token;
	}
q120:(*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<delimitador,ponto>");
		return token;
	}
q121:(*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<delimitador,virgula>");
		return token;
	}
q122:(*pos)++;
  if(txt[*pos] == 'e') goto q123;
  if(txt[*pos] == 'a') goto q150;
  else if(isLetter(txt[*pos])) goto q29;
  else if(txt[*pos] == ' ') goto q83;

  else return token;
q123:(*pos)++;
    if(txt[*pos] == 'r') goto q124;
    else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q124:(*pos)++;
  if(txt[*pos] == 'd') goto q125;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;
  else return token;
q125:(*pos)++;
  if(txt[*pos] == 'a') goto q126;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
  else return token;
q126:(*pos)++;
  if(txt[*pos] == 'd') goto q127;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
  else return token;
q127:(*pos)++;
  if(txt[*pos] == 'e') goto q128;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
  else return token;
q128:(*pos)++;
  if(txt[*pos] == 'i') goto q129;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
  else return token;
q129:(*pos)++;
  if(txt[*pos] == 'r') goto q130;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
  else return token;
q130:(*pos)++;
  if(txt[*pos] == 'o') goto q131;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
  else return token;
q131:(*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<verdadeiro>");
		return token;
	}
q132:(*pos)++;
  if(txt[*pos] == 's') goto q133;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
  else return token;
q133:(*pos)++;
  if(txt[*pos] == 'o') goto q134;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;
  else return token;
q134:(*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<falso>");
		token.valor = getValue(txt, *pos);
		return token;
	}
q135: (*pos)++;
	if(txt[*pos] == 'e') goto q136;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q136: (*pos)++;
	if(txt[*pos] == 'i') goto q137;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q137: (*pos)++;
	if(txt[*pos] == 'r') goto q138;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q138: (*pos)++;
	if(txt[*pos] == 'o') goto q139;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
    else return token;
q139: (*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<inteiro>");
		return token;
	}

q140:(*pos)++;
  if(txt[*pos] == 'g') goto q141;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
  else return token;
q141:(*pos)++;
  if(txt[*pos] == 'i') goto q142;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
  else return token;
q142:(*pos)++;
  if(txt[*pos] == 'c') goto q143;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;
 
  else return token;
q143:(*pos)++;
  if(txt[*pos] == 'o') goto q144;
  else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;

 
  else return token;
q144:(*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<logico>");
		return token;
	}
q145: (*pos)++;
	if(txt[*pos] == ' ') {
		(*pos)++;
		strcpy(token.nome, "<delimitador,doisPontos>");
		return token;
	}
q146: (*pos)++;
	if(txt[*pos] == ' ') {
		(*pos)++;
		strcpy(token.nome, "<delimitador,pontoVirgula>");
		return token;
	}

q147: (*pos)++;
	if(txt[*pos] == ' ') {
		(*pos)++;
		strcpy(token.nome, "<delimitador,PA>");
		return token;
	}
q148: (*pos)++;
	if(txt[*pos] == ' ') {
		(*pos)++;
		strcpy(token.nome, "<delimitador,PF>");
		return token;
	}
q149: (*pos)++;
	if(txt[*pos] == ' ') {
		(*pos)++;
		strcpy(token.nome, "<delimitador,virgula>");
		return token;
	}
q150: (*pos)++;
	if(txt[*pos] == 'r') goto q151;
	else if(isLetter(txt[*pos])) goto q29;
	else if(txt[*pos] == ' ') goto q83;
q151: (*pos)++;
	if(txt[*pos] == ' '){
		(*pos)++;
		strcpy(token.nome, "<var>");
		return token;
	}
q152:(*pos)++;
	if(isNumber(txt[*pos])) goto q152;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q153;
    else return token; 	
q153: (*pos)++;
		char* new_num;
		new_num = getValue(txt, *pos);
		strcpy(token.nome, "<numero,");
		strcat(token.nome, new_num);
		strcat(token.nome, ">");
		return token;
q154:(*pos)++;
	if(txt[*pos] == '*') goto q155;
	else goto q154;
q155:(*pos)++;
	if(txt[*pos] == '/') goto q156;
	else goto q154;
q156:(*pos)++;
	if(txt[*pos] == ' '){
		(*pos)++;
		strcpy(token.nome, "");
		return token;
	}
q157:(*pos)++;
//	if(txt[*pos] == ' '){
//		(*pos)++;
//		strcpy(token.nome, " ");
//		return token;
//	}
//	skip(txt[*pos]);
q158: (*pos)++;
	if(txt[*pos] == 's') goto q159;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;
q159: (*pos)++;
	if(txt[*pos] == 'o') goto q160;
	else if(isLetter(txt[*pos])) goto q29;
    else if(txt[*pos] == ' ') goto q83;
q160: (*pos)++;
	if(txt[*pos] == ' '){
		(*pos)++;
		strcpy(token.nome, "<passo>");
		return token;
	}
	else if(isLetter(txt[*pos])) goto q29;
q161: (*pos)++;
	if(txt[*pos] == '"') goto q162;
	else goto q161;
q162: (*pos)++;
	if(txt[*pos] == ' '){
		(*pos)++;
		strcpy(token.nome, "<delimitador,string>");
		return token;
	}
q29:(*pos)++;
    if(isLetter(txt[*pos])) goto q29;
    if( txt[*pos] == ' ') goto q83;
    else return token;
q83: (*pos)++;
	int new_str;
	char* c = getValue(txt, *pos);
	strcpy(token.nome, "<identificador,");
	strcat(token.nome,  c);
	strcat(token.nome, ">");
   	return token;
q165: (*pos)++;
	if(txt[*pos] == ' ') {
    	(*pos)++;
    	strcpy(token.nome, "<ERRO>");
		token.valor = getValue(txt, *pos);
		return token;
	}
	 
}

void skip(FILE *entrada){
	fscanf(entrada, "%*[^\n]\n", NULL);
}

void readFile(char txt[]) {
    FILE *arquivo_entrada;
    arquivo_entrada = fopen("input.txt","r");
    char line[400];
	
    if (arquivo_entrada) {
        while (fscanf(arquivo_entrada,"%s ", line) != EOF) {
        	if(line[0] == '/' && line[1] == '/'){
				fscanf(arquivo_entrada, "%*[^\n]\n", NULL);
			} else {
            	strcat(line, " ");
            	strcat(txt,line);
				
			}
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
    printf("%s",result);
    FILE *file;
    file = fopen("output2.txt", "w+");
    fprintf(file, result);
    fclose(file);
}

int needValue(char aux[]){
    int c;
    c = atoi(aux);
//    printf("%d", c);
    if(  c == __NUMERO_POSITIVO__ || c == __NUMERO_NEGATIVO__ || c == __IDENTIFICADOR__) return  1;
    return 0;
}
