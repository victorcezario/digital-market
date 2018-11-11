#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

struct orderProduto{
	int codigo;
};
struct modelos {
	char marca[20];
	char modelo[20];
};

struct produtos {
	int codigo;
	char nome[20];
	struct modelos m;
	double valor;
};

struct telefones {
	char fixo[15];
	char movel[16];
};

struct clientes {
	int codigo;
	char nome[50];
	double cpf;
	char sexo[1];
	struct telefones tel;
};

struct carrinhos {
	struct clientes cliente;
	struct produtos produto;
	int quantidade;
	double unitario;
	double desconto;
	double subtotal;
	double total;
};

	struct clientes cliente[3] = {
		{ 996, "PAULO DIAS", 996075987, "M", "3348-5911", "9987-59879" },
		{ 990, "VICTOR CEZARIO", 990589841, "M", "3323-1124", "9147-93819" },
		{ 995, "ANTONIO MARCOS", 995834452, "M", "3328-5977", "9900-53849" } 
	};
	
	struct produtos produto[10] = {
		{ 152, "TECLADO", "ALFAWISE", "V1", 150.00 },
		{ 145, "MONITOR", "LG", "23EA53", 599.00 },
		{ 143, "MOUSE", "LOGITECH", "G403", 220.00 },
		{ 153, "PLACA DE VIDEO", "NVIDIA", "1080 TI", 1000.00 },
		{ 170, "CADEIRA GAMER", "GX", "VENOM SERIOUS", 1200.00 },
		{ 150, "MOUSE PAD", "RAZER", "QCK++", 89.00 },
		{ 189, "OCULOS RIFT", "RIFT", "V2", 700.00 },
		{ 123, "PLAYSTATION", "SONY", "PS4", 1399.00 },
		{ 200, "CONTROLE", "MICROSOFT", "XBOX ONE", 299.00 },
		{ 117, "JOGO", "ROCKSTAR", "GTA V", 99.00 }
	};	
	
	struct carrinhos carrinho[3];

int mostraMenuInicial();
struct clientes cadastrarCliente();
int geraCodigoCliente(double cpf);
void listarClientes(struct clientes cliente[3]);
struct produtos cadastrarProduto(); 
int geraCodigoProduto(char nomeProduto[30]); 
void listarProdutos(struct produtos produto[10]);
void efetuarVenda(struct clientes cliente[3], struct produtos produto[10], struct carrinhos carrinho[3]);
struct clientes localizaCliente(int codigo, struct clientes cliente[3]);
struct produtos localizaProduto(int codigo, struct produtos produto[10]);
void finalizarVenda(struct carrinhos carrinho[3]);
void listarCarrinho(struct carrinhos carrinho[3]);
double calculaSubtotal(struct carrinhos carrinho[3]); 
double calculaTotal(double subtotal, double desconto);

void main() {
	int opcao = 1;
	while(opcao != 0) {
	opcao = mostraMenuInicial();
	}
}

int mostraMenuInicial() {
	int opcao;
    printf("===============================================================================\n");
    printf("===========================BEM VINDO AO MERCADO DIGITAL========================\n");
    printf("===============================================================================\n");
    printf("1 - Cadastrar um Cliente\n");
    printf("2 - Cadastrar um Produto\n");
    printf("3 - Listar os Clientes\n");
    printf("4 - Listar os Produtos\n");
    printf("5 - Efetuar uma Venda\n");
	printf("6 - Localizar Cliente\n");
    printf("0 - Sair do Mercado Digital\n");
    printf("===============================================================================\n");
    printf("Digite sua opcao: \n");
    scanf("%d",&opcao);

    switch(opcao) {
    	case 1:
   			system("cls");
    		for(int i = 2; i > 0; i--) {
    			cliente[i] = cliente[i-1];
			}
    		cliente[0] = cadastrarCliente();
    	break;
    	case 2:
    		system("cls");
    		for(int i = 10; i > 0; i--) {
    			produto[i] = produto[i-1];
			}
    		produto[0] = cadastrarProduto();
    	break;    	
    	case 3:
    		system("cls");
    		listarClientes(cliente);
    		system ("pause");
    	break; 
    	case 4:
    		system("cls");
    		listarProdutos(produto);
    		system ("pause");
    	break;  
    	case 5:
    		system("cls");
    		efetuarVenda(cliente, produto, carrinho);
    		system ("pause");
    	break;  
		case 6:
    		system("cls");
    		efetuarVenda(cliente, produto, carrinho);
    		system ("pause");
    	break;   
   	case 0:
    		printf("Volte sempre!\n");
    		system ("pause");
    	break; 	
    	default:
    		printf("Opcao invalida!\n");
    		system ("pause");
	}
	
	system("cls");
	return opcao;
	
}
struct clientes cadastrarCliente(){

	printf("===============================================================================\n");
	printf("==                  CADASTRO DE CLIENTES NO MERCADO DIGITAL                  ==\n");
	printf("===============================================================================\n");
	
	struct clientes c;
	
	printf("Digite o nome do cliente: ");
	fflush(stdin);
	gets(c.nome);
	
	printf("Digite o CPF do %s: ",c.nome);
	scanf("%lf",&c.cpf);

	printf("Digite o sexo do %s: ",c.nome);
	fflush(stdin);
	scanf("%s",&c.sexo);

	printf("Digite o telefone fixo do %s: ",c.nome);
	fflush(stdin);
	gets(c.tel.fixo);

	printf("Digite o telefone movel do do %s: ",c.nome);
	fflush(stdin);
	gets(c.tel.movel);
	
	c.codigo = geraCodigoCliente(c.cpf);
	
	printf("O codigo para o cliente gerado foi: %d\n",c.codigo);
		
	system ("pause");
	
	return c;

}
int geraCodigoCliente(double cpf) {
	return cpf = rand() % 100;
}
void listarClientes(struct clientes cliente[3]) {
	
	printf("===============================================================================\n");
	printf("==                  CLIENTES CADASTRADOS NO MERCADO DIGITAL                  ==\n");
	printf("===============================================================================\n");
	printf("CODIGO  NOME            CPF             SEXO    TEL             CEL\n");

	for(int i = 0; i < 3; i++) {
		printf("%d     %s      %.0lf    %s    %s    %s\n",cliente[i].codigo,cliente[i].nome,cliente[i].cpf,cliente[i].sexo,cliente[i].tel.fixo,cliente[i].tel.movel);
	} 
	
	printf("===============================================================================\n");
	
	//	system ("pause");
}
struct produtos cadastrarProduto() {

	printf("===============================================================================\n");
	printf("==                  CADASTRO DE PRODUTOS NO MERCADO DIGITAL                  ==\n");
	printf("===============================================================================\n");

	struct produtos p;
		
	printf("Digite o nome do produto: ");
	fflush(stdin);
	gets(p.nome);

	printf("Digite a marca do %s: ",p.nome);
	fflush(stdin);
	gets(p.m.marca);

	printf("Digite o modelo do %s de marca %s: ",p.nome,p.m.marca);
	fflush(stdin);
	gets(p.m.modelo);

	printf("Digite o valor para %s %s %s R$: ",p.nome,p.m.marca,p.m.modelo);
	fflush(stdin);
	scanf("%lf",&p.valor);

	p.codigo = geraCodigoProduto(p.nome);

	printf("O codigo para o produto gerado foi: %d\n",p.codigo);
	
	system ("pause");
	return p;

}
int geraCodigoProduto(char nomeProduto[30]) {
	//return nomeProduto[30] = rand() % 100;
    return ("%c",nomeProduto[0]) + ("%c",nomeProduto[1]);

}
void listarProdutos(struct produtos produto[10]) {
	printf("===============================================================================\n");
	printf("==                  PRODUTOS DISPONIVEIS NO MERCADO DIGITAL                  ==\n");
	printf("===============================================================================\n");
	
	for(int i = 0; i < 10; i++) {
		printf("%d - %s - %s - %s - R$ %.2lf \n",produto[i].codigo,produto[i].nome,produto[i].m.modelo,produto[i].m.marca,produto[i].valor);
	}
	
	printf("===============================================================================\n");

	//system ("pause");
	
}
void efetuarVenda(struct clientes cliente[3], struct produtos produto[10], struct carrinhos carrinho[3]) {
	int codigo, codigo_p;
	
	listarClientes(cliente);
	
	printf("Digite o codigo do cliente que esta comprando: ");
	scanf("%d",&codigo);
	
	system("cls");
	
	listarProdutos(produto);
	
	carrinho[0].cliente = localizaCliente(codigo, cliente);
	
	printf("CARRINHO DE COMPRA DE %s \n",carrinho[0].cliente.nome);
	
	for(int i = 0; i < 3; i++) {
		
	printf("Digite o codigo do produto %d a ser inserido no carrinho: ",i);
	scanf("%d",&codigo_p);
	
	carrinho[i].produto = localizaProduto(codigo_p, produto);
	
	printf("Digite a quantidade de %s %s que deseja comprar: ",carrinho[i].produto.nome,carrinho[i].produto.m.modelo);
	scanf("%d",&carrinho[i].quantidade); 
	
	carrinho[i].unitario = carrinho[i].produto.valor;
	
	}
	
	
	finalizarVenda(carrinho);
	
}
struct clientes localizaCliente(int codigo, struct clientes cliente[3]) {
	struct clientes c;
	
	for(int i = 0; i < 3; i++) {
		if(cliente[i].codigo == codigo ) {
		return cliente[i];
		}
	}
	
	return c;
	
}
struct produtos localizaProduto(int codigo_p, struct produtos produto[10]) {
	
	for(int i = 0; i < 10; i++) {
		if(produto[i].codigo == codigo_p) {
		return produto[i];
		}
	}
	
}
void finalizarVenda(struct carrinhos carrinho[3]) {
	
	printf("===============================================================================\n");	
	printf("Insira o CUPOM DE DESCONTO: ");
	scanf("%lf",&carrinho[0].desconto);	
	
	listarCarrinho(carrinho);
	
	carrinho[0].subtotal = calculaSubtotal(carrinho);
	carrinho[0].total = calculaTotal(carrinho[0].subtotal,carrinho[0].desconto);
	
	printf("===============================================================================\n");
	printf("SUBTOTAL: R$ %.lf\n",carrinho[0].subtotal);
	printf("DESCONTO: R$ %.lf\n",carrinho[0].desconto);
	printf("TOTAL DA COMPRA: R$ %.lf\n",carrinho[0].total);
	printf("===============================================================================\n");
}
void listarCarrinho(struct carrinhos carrinho[3]) {
	system("cls");
	printf("===============================================================================\n");
	printf("==                            FINALIZANDO A VENDA                            ==\n");
	printf("===============================================================================\n");
	printf("DADOS DO CLIENTE: %d - %s - %0.lf\n",carrinho[0].cliente.codigo,carrinho[0].cliente.nome,carrinho[0].cliente.cpf);
	printf("===============================================================================\n");
	printf("PRODUTOS COMPRADOS:\n");
	for(int i = 0; i < 3; i++) {
		printf("%d - %s %s %s - QTD: %d VL.UNIT: R$ %.2lf VL.TOTAL: %.2lf \n",carrinho[i].produto.codigo,carrinho[i].produto.nome,carrinho[i].produto.m.marca,carrinho[i].produto.m.modelo,carrinho[i].quantidade,carrinho[i].unitario,(carrinho[i].unitario*carrinho[i].quantidade));
	}

}
double calculaSubtotal(struct carrinhos carrinho[3]) {
	for(int i = 0; i < 3; i++) {
		carrinho[0].subtotal = carrinho[0].subtotal + (carrinho[i].unitario * carrinho[i].quantidade);
	} 
	return carrinho[0].subtotal;
} 
double calculaTotal(double subtotal, double desconto) {
	float total;
	total = subtotal - desconto;
	return total;
}