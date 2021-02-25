#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

double identificaFuncao(double x){
	return cos(x);
}

double bissecao(){
	printf("Voce escolheu o metodo da bissecao!\n");
	/*
	Precisamos de dois parâmetros iniciais dados pelo usuário. os limites do intervalo [a;b].
	A exigência é que o sinal de f(Xi) mude de a para b, ou seja, f(a)*f(b).
	*/
	double a, b;
	printf("Digite o intervalo em que deseja buscar a raiz. Diremos se for valido\n");
	scanf("%lf%lf", &a,&b);
	double fA, fB;
	fA=identificaFuncao(a);
	fB=identificaFuncao(b);
	while(fA*fB>=0){
		printf("Digite um novo intervalo, em que haja mudanca de sinal de f(a) para f(b)\n");
		scanf("%lf%lf", &a,&b);
		fA=identificaFuncao(a);
		fB=identificaFuncao(b);
	}
	printf("Parabens! Seu intervalo inicial e valido. Vamos comecar as iteracoes\n" );
	/*
	Se você chegou aqui, o intervalo [a;b] é válido.
	Hora de começar o algoritmo
	*/
	double Xc,xant, fXc, precisao; 
	int i;
	printf("Digite um numero de iteracoes\n");
	scanf("%d", &i);
	printf("Digite a precisao desejada\n");
	scanf("%lf", &precisao);
	xant = 0;

	double erro = 0;

	while(i>0){
		Xc = (a+b)/2;
		fXc = identificaFuncao(Xc);
		if(fXc*fA>0)
			a = Xc;
		else
			b = Xc;
		erro = fabs(Xc-xant);
		if (erro < precisao){ 
        	printf("O valor mais proximo da raiz foi : %lf; com erro de: %lf\n", Xc,erro);
        	return Xc;
        }
		i--;
		xant = Xc;
	}
	printf("O valor mais proximo da raiz foi : %lf; com erro de: %lf\n", Xc,erro);
	
	return Xc;
}

double secantes() {
	printf("Voce escolheu o metodo da secante\n");
	double x0, x1, precisao;
	int i, j;
	printf("Digite o intervalo em que deseja buscar a raiz. Diremos se for valido\n");
	scanf("%lf%lf", &x0, &x1);
	printf("Digite o numero de iteracoes\n");
	scanf("%d", &i);
	printf("Digite a precisao desejada\n");
	scanf("%lf", &precisao);
    double x2,f0,f1,erro;
    f0 = identificaFuncao(x0);
    for (j=i; j>0; j--){
        f1 = identificaFuncao(x1);
        x2=x1-(x1-x0)*f1/(f1-f0);
        erro = fabs(x2-x1);
        if (erro < precisao){ 
        	printf("O valor mais proximo da raiz foi : %lf; com erro de: %lf\n", x2,erro);
        	return x2;
        }
        x0=x1;
        x1=x2;
        f0=f1;
    }
 	printf("O valor mais proximo da raiz foi : %lf; com erro de: %lf\n", x2,erro);
    return x2; 
	
}

double jacobiRichardson(){
/*
	X é o vetor chute, 
	A é matriz dos coeficientes, 
	b o vetor com os termos constantes,
	i o numero máximo de iterações
	E é a precisão
	n é o número de equações e, portanto, a ordem das
*/
	printf("Voce escolheu o metodo iterativo de Jacobi-Richardson\n");
	int n, j, i, soma, parar = 1;
	double X[n], b[n], x[n], E;
	double A[n][n];
	printf("Digite o tamanho da matriz A\n");
	scanf("%d", &n);
	printf("Insira o vetor chute inicial\n");
	for(i=0;i<n;i++)
		scanf("%lf",&X[i]);
	printf("Entre com a matriz A\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Digite o termo a%d%d\n",i,j);
			scanf("%lf",&A[i][j]);
		}
	}
	printf("Entre com o vetor de termos constantes b\n");
	for(i=0;i<n;i++){
		scanf("%lf",&b[i]);
	}
	printf("Digite o numero de iteracoes\n");
	scanf("%d", &i);
	printf("Digite a precisao desejada\n");
	scanf("%lf", &E);
	int k = 0;
	while(parar == 1 && k<i){
	 	for(i=0;i<n;i++){
	 		soma = 0;
	 		for(j=0;j<n;j++){
	 			if(j != i){
	 				soma = soma + (A[i][j]*X[j])/A[i][i];
	 			}
	 			x[i] = (b[i]/A[i][i]) - soma;
	 		}
	 	}
	 	
	 	int normax, normaX;
	 	int soma1,soma2;
	 	soma1 = 0;
	 	soma2 = 0;
	 	for(i=0;i<n;i++){
	 		soma1+= x[i]*x[i];
	 		soma2 += X[i]*X[i];
	 	}
	 	normax = sqrt(soma1);
	 	normaX = sqrt(soma2);
	 	if (fabs(normax - normaX)< E){
	 		parar = 0;
	 	}
	 	else{
	 	
	 		for(i=0;i<n;i++){
	 			X[i] = x[i];
	 			printf("%lf ",x[i]);
	 			printf("\n");
	 		}
	 	}
	 	k++;
 	}
 	printf("Solução: ");
 	for(i=0;i<n;i++){
 		printf("%lf ", X[i]);
 	}
}
   
double gaussSeidel(){
	printf("Voce escolheu o metodo iterativo de Jacobi-Richardson\n");
	float a[10][10], b[10], x[10], y[10];
    int n = 0, m = 0, i = 0, j = 0;
    printf("Digite o tamanho da matriz A\n");
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "\nQuais os valores de X, Y e Z nas coordenadas da Matriz: (" << i << ", " << j << "): ";
            cin >> a[i][j];
        }
    }
    cout << "\n\nDigite os valores do resultado de cada equacao (a direita do ' = ' )\n";
    for (i = 0; i < n; i++)
    {
        cout << "Resultado da equacao em :(" << i << ", " << j << ") ";
        cin >> b[i];
    }
    cout << "\n Qual o palpite inicial (padrÃ£o: 0, 0, 0):\n";
    for (i = 0; i < n; i++)
    {
        cout << "Valores iniciais:(" << i<<"):";
        cin >> x[i];
    }
    cout << "\nQuantas iteracoes deseja realizar? : ";
    cin >> m;
    cout << "\n\nResultados:\n";
    while (m > 0)
    {
        for (i = 0; i < n; i++)
        {
            y[i] = (b[i] / a[i][i]);
            for (j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
                x[i] = y[i];
            }
           cout << (i + 1, y[i]) << endl;
        }
        cout << " \n ";
        m--;
    }
    return 0;
}
   
double lagrange(){
	cout <<"Voce escolheu o Metodo de Lagrange" << endl;
	int k,i,n,j;
	long double l,p;
	cout <<"Digite o número de pontos disponiveis" << endl;
	cin >> n;
	long double x[n],f[n];
	cout << "Digite os valores X dos pontos" << endl;
	for(i=0;i<n;i++){
		cin >> x[i];
	}
	cout << "Digite os valores Y dos pontos" << endl;
	for(i=0;i<n;i++){
		cin >> f[i];
	}
	cout <<"Digite o X cuja imagem e desconhecida" << endl;
	cin >> p;
	long double resp = 0;
	for(k=0;k<n;k++){
		l = 1;
		for(i=0;i<n;i++){
			if(i!=k){
				l = l*((p-x[i])/(x[k]-x[i]));
			}
		}
		resp = resp + (f[k]*l);
	}
	cout <<"O valor aproximado pelo polinomio no X escolhido e " << resp << endl; 
	return resp;
}

double newton(){
	cout <<"Voce escolheu o metodo de Newton";	
	int n,i,j;
	cout <<"Digite o número de pontos disponíveis: ";
	cin >> n;
	double t[n][n],p;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			t[i][j] = 0;
		}
	}
	double x[n];
	cout <<"Digite os valores X dos pontos: ";
	for(i=0;i<n;i++){
		cin >> x[i];
	}
	cout <<"Digite os valores Y dos pontos: ";
	for(i=0;i<n;i++){
		cin >> t[i][0];
	}
	//preenche a matriz
	cout << "Digite o valor de X cuja imagem e desconhecida: ";
	cin >> p;
	cout << endl;
	//preenche coluna da matriz dos coeficientes com os yi
	for(j=1;j<n;j++){
		for(i=0;i<n-j;i++){
			t[i][j] = (t[i+1][j-1]-t[i][j-1])/((x[j+i]) - (x[i])) ;
		}
	}
	// cálculo do polinômio no ponto
	double resp = t[0][0];
	double produto = 1;

	for(i=1;i<n;i++){
		produto = (p - x[i-1])*produto;
		resp = resp + t[0][i]*produto;
	}
	cout << "O valor da função no ponto é: " << resp << endl;
	return resp;
}

void simpson1(){
	double a,b,h,resp,pares,impares;
	int i,n;
	resp = 0;
	cout << "Entre com o número de pontos: ";
	cin >> n;
	cout << endl;
	cout << "Entre com o limite inferior e superior do intervalo, respectivamente: ";
	cin >> a >> b;
	cout << endl;
	h = (b-a)/(n-1);
	cout << h << endl;
	double x[n];
	for(i=0;i<n;i++){
		x[i] = a+(h*i);
	}
	impares = pares = 0;
	for(i=1;i<=n-1;i++){
		if(i%2 == 0){
			pares = pares + 4*identificaFuncao(x[i]);
		}
		else{
			impares = impares + 2*identificaFuncao(x[i]);
		}
	}

	resp = h/3*(identificaFuncao(x[0]) + identificaFuncao(x[n]) + pares + impares);
	cout << "A integral no intervalo [" << a << ", " << b << "]" <<" é: " << resp << endl;
}

void simpson3(){
	double a,b,h,resp,dois,tres;
	int i,n;
	resp = 0;
	cout << "Entre com o número de pontos: ";
	cin >> n;
	cout << endl;
	cout << "Entre com o limite inferior e superior do intervalo, respectivamente: ";
	cin >> a >> b;
	cout << endl;
	h = (b-a)/(n-1);
	cout << h << endl;
	double x[n];
	for(i=0;i<n;i++){
		x[i] = a+(h*i);
	}
	dois = tres = 0;
	int cont = 0;
	for(i=1;i<=n-1;i++){
		if(cont<2){
			tres+= 3* identificaFuncao(x[i]);
			cont++;
		}
		else{
			dois+= 2* identificaFuncao(x[i]);
			cont = 0;
		}
	}
	resp = 3*h/8*(identificaFuncao(x[0]) + identificaFuncao(x[n]) + tres + dois);
	cout << "A integral no intervalo [" << a << ", " << b << "]" <<" é: " << resp << endl;

}

void trapezios(){
	double a, b, h, somatorio=0, E;
	int n, i;
	printf("Entre com os limite inferior e superior do intervalo: ");
	scanf("%lf%lf",&a,&b);
	printf("\n");	
	printf("Entre com o numero de nos: ");
	scanf("%d",&n);
	n = max(n,2);
	printf("\n");
	h=(b-a)/n;
	double x = a;
	somatorio = (identificaFuncao(a) + identificaFuncao(b))*h/2;
	for (i=0; i<n-1; i++){
		somatorio += identificaFuncao(x)*h;
		x+=h;
	}
	
	printf("O resultado da área é: %.3lf\n", somatorio);

}

void euler(){
	
}

void rungekutta2(){
	
}

void rungekutta4(){
	
}

int main() {
	int algoritmo;
	
	printf("Digite o número do algoritmo que deseja usar:\n");
	printf("	1 - Metodo da Bissecao\n");
	printf("	2 - Metodo das Secantes\n");
	printf("	3 - Metodo iterativo de Jacobi-Richardson\n");
	printf("	4 - Metodo iterativo de Gauss-Seidel\n");
	printf("	5 - Metodo da interpolacao de Lagrange\n");
	printf("	6 - Metodo da interpolacao de Newton\n");
	printf("	7 - Metodo da integracao baseada na Regra dos Trapezios Generalizada\n");
	printf("	8 - Metodo da integracao baseada na Regra de 1/3 de Simpson Generalizada\n");
	printf("	9 - Metodo da integracao baseada na Regra de 3/8 de Simpson Generalizada\n");
	printf("	10 - Metodo de Euler para Solucao de PVI\n");
	printf("	11 - Metodo de Runge-Kutta de 2ª Ordem\n");
	printf("	12 - Metodo de Runge-Kutta de 4ª Ordem\n");
	
	scanf("%d", &algoritmo);
	
	switch(algoritmo){
		case 1:
			bissecao();
		break;
	
		case 2:
			secantes();
		break;
		
		case 3:
			jacobiRichardson();
		break;
	
		case 4:
			gaussSeidel();
		break;

		case 5:
			lagrange();
		break;

		case 6:
			newton();
		break;
		
		case 7:
			trapezios();
		break;	
		case 8:
			simpson1();
		break;		
		case 9:
			simpson3();
		break;
		
		case 10:
			euler();
		break;
		
		case 11:
			rungekutta2();
		break;
		
		case 12:
			rungekutta4();
		break;
		
	}	
	return 0;
}
