// Giovanni Alvissus
// Trabalho final APC 2021_1
// Software de cadastrar voos e reservas

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define tam_voo 5
#define tam_data 9
#define tam_horario 5
#define tam_linha 1000
#define tam_i 1000
#define tam_reserva 7
#define tam_cpf 12
#define tam_nome 150
#define tam_excluir 8

#define VOO voo.numero_voo
#define RES num_reserva
#define CP reserva.cpf
#define MAX voo.max_passageiros

typedef struct // Cria uma STRUCT para armazenar os dados do voo
{
	char numero_voo[tam_voo];
	int dia;
	int mes;
	int ano;
	int hora;
	int min;
	int max_passageiros;
} registro_voo;
registro_voo voo;

typedef struct // Cria uma STRUCT para armazenar os dados da reserva
{
	char cpf[tam_cpf];
	char nome[tam_nome];
	int sexo;
	int dia;
	int mes;
	int ano;
} passageiro;
passageiro reserva;

int main()	// Main
{
	int opcao = 0;
	while (opcao != 9)
	{
		menu();

		int val_opc = 0;
		while (val_opc != 1)
		{
			printf(" Digite a opcao desejada: ");
			scanf("%d", &opcao);
			printf("\n");

			if (opcao < 1 || opcao > 10)
			{
				printf(" Escolha entre 1 e 10\n\n");
			}
			else
			{
				val_opc = 1;
			}
		}

		if (opcao == 1)
		{
			opcao_1();
		}
		if (opcao == 2)
		{
			opcao_2();
		}
		if (opcao == 3)
		{
			opcao_3();
		}
		if (opcao == 4)
		{
			opcao_4();
		}
		if (opcao == 5)
		{
			opcao_5();
		}
		if (opcao == 6)
		{
			opcao_6();
		}
		if (opcao == 7)
		{
			opcao_7();
		}
		if (opcao == 8)
		{
			opcao_8();
		}
		if (opcao == 10)
		{
			limitacoes();
		}
	}
	FILE *file;
	file = fopen("Arquivo Voo temp.txt", "w");
	fclose(file);
	remove("Arquivo Voo temp.txt");

	return 0;
}

void menu()	// Menu
{
	clear();
	printf("\n===============================================================\n\n\n");
	printf("  MENU DE OPCOES\n\n");
	printf(" 1) Cadastrar voo \n");
	printf(" 2) Cadastrar reserva \n");
	printf(" 3) Consultar voo \n");
	printf(" 4) Consultar reserva \n");
	printf(" 5) Consultar passageiro \n");
	printf(" 6) Cancelar voo \n");
	printf(" 7) Cancelar reserva \n");
	printf(" 8) Excluir voo \n");
	printf(" 9) Sair do programa \n");
	printf(" 10) Acesse informacoes importantes sobre o software\n\n\n");
}

int opcao_1()	// CADASTRAR VOO
{
	int alterar = 1;
	while(alterar != 2)
	{
		clear();
		printf("===============================================================\n\n");
		printf("                        CADASTRAR VOO \n\n");

		printf(" Obs: Caso queira voltar ao menu basta digitar 'MENU'\n");
		printf("---------------------------------------------------------------\n\n");

		int valor = 0;
		int validador_voo = 0;	// Valida os dados informados

		while (validador_voo != 1)
		{
			printf(" Numero do voo (JEB-XXXX): JEB-");
			scanf("%s", VOO);
			printf("\n");

			if (strcmp(VOO, "MENU") == 0)
			{
				return 0;
			}

			if (VOO[0] > 47 && VOO[0] < 58 && VOO[1] > 47 && VOO[1] < 58 &&
					VOO[2] > 47 && VOO[2] < 58 && VOO[3] > 47 && VOO[3] < 58 &&
					VOO[4] == NULL)
			{
				if (proc_voo(VOO, 0) == 1)
				{
					printf(" Voo ja cadastrado\n\n");
				}
				else
				{
					validador_voo = 1;
				}
			}
			else
			{
				printf(" Favor inserir um numero valido!\n\n");
			}
		}

		printf("---------------------------------------------------------------\n\n");

		int validador_maximo = 0;
		while (validador_maximo == 0)
		{
			printf(" Maximo de passageiros (<1000): ");
			scanf("%d", &voo.max_passageiros);
			printf("\n");

			int inteiro = MAX;

			if (MAX > 999)
			{
				printf(" Favor inserir uma capacidade valida!\n\n");
			}
			else
			{
				validador_maximo = 1;
			}


		}


		printf("---------------------------------------------------------------\n\n");

		char data[tam_data];
		char horario[tam_horario];
		int validador_checagem_data = 0;

		while (validador_checagem_data == 0)
		{
			int validador_data = 0;
			while (validador_data == 0)
			{
				printf(" Data (informar no formato ddmmaaaa): ");
				scanf("%s", data);
				printf("\n");

				if (strcmp(data, "MENU") == 0)
				{
					return 0;
				}

				if (data[0] > 47 && data[0] < 58 && data[1] > 47 && data[1] < 58 &&
						data[2] > 47 && data[2] < 58 && data[3] > 47 && data[3] < 58 &&
						data[4] > 47 && data[4] < 58 && data[5] > 47 && data[5] < 58 &&
						data[6] > 47 && data[6] < 58 && data[7] > 47 && data[7] < 58 &&
						data[8] == NULL)
				{
					voo.dia = (data[0] - 48) * 10 + data[1] - 48;
					voo.mes = (data[2] - 48) * 10 + data[3] - 48;
					voo.ano = (data[4] - 48) * 1000 + (data[5] - 48) * 100 + (data[6] - 48) * 10 + data[7] - 48;

					validador_data = 1;
				}
				else
				{
					printf(" Favor inserir uma data valida. \n\n");
				}
			}

			int validador_horario = 0;
			while (validador_horario == 0)
			{
				printf(" Horario do voo (informar no formato hhmm): ");
				scanf("%s", horario);
				printf("\n");

				if (strcmp(horario, "MENU") == 0)
				{
					return 0;
				}

				if (horario[0] > 47 && horario[0] < 58 && horario[1] > 47 || horario[1] < 58 &&
						horario[2] > 47 && horario[2] < 58 && horario[3] > 47 && horario[3] < 58 &&
						horario[4] == NULL)
				{
					voo.hora = (horario[0] - 48) * 10 + horario[1] - 48;
					voo.min = (horario[2] - 48) * 10 + horario[3] - 48;

					validador_horario = 1;
				}
				else
				{
					printf(" Favor inserir um horario valido. \n\n");
				}
			}

			if (checagem_data(voo.dia, voo.mes, voo.ano, voo.hora, voo.min, 1) == 1)
			{
				validador_checagem_data = 1;
			}
			else
			{
				printf(" Favor marcar o voo no minimo 24h antes e/ou informar uma data existente!\n\n");
			}
		}

		clear();
		printf("===============================================================\n\n");
		printf("                     REVISANDO DADOS DO VOO \n\n\n");

		printf(" Numero do voo: JEB-%s \n", voo.numero_voo);
		printf(" Maximo de passageiros: %03d\n", voo.max_passageiros);

		printf(" Data: %02d/%02d/%04d - %02d:%02d\n", voo.dia, voo.mes, voo.ano, voo.hora, voo.min);

		printf("\n\n");
		printf(" Gostaria de altera-lo?\n\n");
		printf(" 1- Sim, irei alterar\n 2- Nao, quero voltar ao menu inicial\n\n");
		printf(" Escolha uma opcao: ");
		scanf("%d", &alterar);

		if (alterar == 2)
		{
			arq_voo(voo.numero_voo, voo.max_passageiros, voo.dia, voo.mes, voo.ano, voo.hora, voo.min);
			return 0;
		}
	}
}

int opcao_2()	// CADASTRAR RESERVA
{
	int alterar = 1;
	while (alterar == 1)
	{
		int repetidor = 0;
		while (repetidor == 0)
		{
			clear();
			printf("===============================================================\n\n");
			printf("                      CONSULTAR PASSAGEIRO \n\n");

			printf(" Obs: Caso queira voltar ao menu basta digitar 'MENU'\n");
			printf("---------------------------------------------------------------\n\n");

			int validador_cpf = 0;
			while (validador_cpf == 0)
			{
				printf(" CPF (XXXXXXXXXXX): ");
				scanf("%s", CP);
				printf("\n");

				if (strcmp(CP, "MENU") == 0)
				{
					return 0;
				}

				if(valida_cpf(CP) == 0)
				{
					printf(" Favor inserir um CPF valido!\n\n");
				}
				else
				{
					if (proc_passageiro(CP) == 1)
					{
						cadastrar_reserva(reserva.cpf);
						return 0;
					}
					else
					{
						int escolha = 0;
						int validador_escolha = 0;

						printf(" Parece que esse CPF nao possui cadastro, gostaria de cadastrar?\n\n");
						printf(" 1- Sim, quero cadastrar\n");
						printf(" 2- Nao, quero tentar outro\n");
						printf(" 3- Nao, quero voltar ao menu inicial\n\n");

						while (validador_escolha == 0)
						{
							printf(" Escolha: ");
							scanf("%d", &escolha);

							if (escolha != 1 && escolha != 2 && escolha != 3)
							{
								printf(" Favor escolher uma opcao valida!\n\n");
							}
							else
							{
								if (escolha == 1)
								{
									validador_escolha = 1;
									validador_cpf = 1;
									repetidor = 1;
								}
								else if (escolha == 2)
								{
									validador_escolha = 1;
									validador_cpf = 1;
								}
								else if (escolha == 3)
								{
									return 0;
								}
							}
						}
					}
				}
			}
		}
		printf("---------------------------------------------------------------\n\n");

		int validar_nome = 0;
		while (validar_nome == 0)
		{
			printf(" Nome (maximo de 150 caracteres): ");
			getc(stdin);
			gets(reserva.nome);
			printf("\n");

			if (strcmp(reserva.nome, "MENU") == 0)
			{
				return 0;
			}

			if (valida_nome(reserva.nome) == 1)
			{
				validar_nome = 1;
			}
			else
			{
				printf(" Favor inserir um nome valido\n\n");
			}
		}


		printf("---------------------------------------------------------------\n\n");

		int validador_sexo = 0;
		while (validador_sexo == 0)
		{
			printf(" Sexo:\n\n");
			printf(" 1- Masculino \n 2- Feminino \n 3- Prefiro nao informar\n\n");
			printf(" Escolha sua opcao: ");
			scanf("%d", &reserva.sexo);
			printf("\n\n");

			if (reserva.sexo != 1 && reserva.sexo != 2 && reserva.sexo != 3)
			{
				printf(" Favor escolher uma opcao valida!\n\n");
			}
			else
			{
				validador_sexo = 1;
			}
		}

		printf("---------------------------------------------------------------\n\n");

		char data[tam_data];
		int validador_checagem_data = 0;
		while (validador_checagem_data == 0)
		{
			int validador_data = 0;
			while (validador_data == 0)
			{
				printf(" Data de nascimento (ddmmaaaa):");
				scanf("%s", data);
				printf("\n");

				if (strcmp(data, "MENU") == 0)
				{
					return 0;
				}

				if (data[0] > 47 && data[0] < 58 && data[1] > 47 && data[1] < 58 &&
						data[2] > 47 && data[2] < 58 && data[3] > 47 && data[3] < 58 &&
						data[4] > 47 && data[4] < 58 && data[5] > 47 && data[5] < 58 &&
						data[6] > 47 && data[6] < 58 && data[7] > 47 && data[7] < 58 &&
						data[8] == NULL)
				{
					reserva.dia = (data[0] - 48) * 10 + data[1] - 48;
					reserva.mes = (data[2] - 48) * 10 + data[3] - 48;
					reserva.ano = (data[4] - 48) * 1000 + (data[5] - 48) * 100 + (data[6] - 48) * 10 + data[7] - 48;

					validador_data = 1;
				}
				else
				{
					printf("\n Favor inserir uma data valida. \n\n");
				}
			}

			if (checagem_data(reserva.dia, reserva.mes, reserva.ano, NULL, NULL, 2) == 1)
			{
				validador_checagem_data = 1;
			}
			else
			{
				printf(" Favor informar uma data de nascimento valida!\n\n");
			}
		}

		clear();
		printf("===============================================================\n\n");
		printf("                   REVISANDO DADOS DO PASSAGEIRO \n\n\n");

		printf(" Nome do passageiro: %s \n", reserva.nome);
		printf(" CPF: %c%c%c.%c%c%c.%c%c%c-%c%c\n", reserva.cpf[0], reserva.cpf[1], reserva.cpf[2], reserva.cpf[3],
			   reserva.cpf[4], reserva.cpf[5], reserva.cpf[6], reserva.cpf[7], reserva.cpf[8], reserva.cpf[9], reserva.cpf[10]);
		printf(" Data de nascimento: %02d/%02d/%04d\n", reserva.dia, reserva.mes, reserva.ano);

		if (reserva.sexo == 1)
		{
			printf(" Sexo: Masculino\n");
		}
		else if (reserva.sexo == 2)
		{
			printf(" Sexo: Feminino\n");
		}
		else
		{
			printf(" Sexo: Prefere nao informar\n");
		}


		printf("\n\n");
		printf(" Gostaria de altera-lo?\n\n");
		printf(" 1- Sim, irei alterar\n 2- Nao, quero salvar e cadastrar uma reserva\n\n");

		int validador_escolha = 0;
		while (validador_escolha == 0)
		{
			printf(" Escolha uma opcao: ");
			scanf("%d", &alterar);

			if (alterar == 2)
			{
				arq_passageiro(reserva.cpf, reserva.nome, reserva.sexo, reserva.dia, reserva.mes, reserva.ano);

				cadastrar_reserva(reserva.cpf, reserva.nome);
				return 0;
			}
			else if (alterar != 2 && alterar != 1)
			{
				printf(" Favor escolher uma opcao valida!\n\n");
			}
			if (alterar == 1)
			{
				validador_escolha = 1;
			}
		}
	}
}

int cadastrar_reserva(CPF)	// CADASTRAR RESERVA - Continuação
{
	int validacao_cadastro = 0;
	while (validacao_cadastro == 0)
	{
		char num_reserva[tam_reserva];
		clear();
		printf("===============================================================\n\n");
		printf("                      CADASTRAR RESERVA \n\n");

		proc_passageiro(CPF, 1);

		printf(" Obs: Caso queira voltar ao menu basta digitar 'MENU'\n");
		printf("---------------------------------------------------------------\n\n");

		int validador_reserva = 0;
		while (validador_reserva == 0)
		{
			printf(" Numero da reserva (GB-XXXXXX): GB-");
			scanf("%s", num_reserva);
			printf("\n");

			if (strcmp(num_reserva, "MENU") == 0)
			{
				return 0;
			}

			if (RES[0] < 48 || RES[0] > 57 || RES[1] < 48 || RES[1] > 57 ||
					RES[2] < 48 || RES[2] > 57 || RES[3] < 48 || RES[3] > 57 ||
					RES[4] < 48 || RES[4] > 57 || RES[5] < 48 || RES[5] > 57 ||
					RES[6] != NULL)
			{
				printf(" Favor inserir um numero valido!\n\n");
			}
			else
			{
				validador_reserva = 1;
			}

			if (validador_reserva == 1)
			{
				if (proc_reserva(num_reserva) == 1)
				{
					printf(" Numero de reserva ja cadastrado\n\n");
					validador_reserva = 0;
				}
			}
		}

		printf("---------------------------------------------------------------\n\n");

		int validador_voo = 0;
		char num_voo[5];

		while (validador_voo == 0)
		{
			printf(" Voo (JEB-XXXX): JEB-");
			scanf("%s", num_voo);
			printf("\n");

			if (num_voo[0] < 48 || num_voo[0] > 57 || num_voo[1] < 48 || num_voo[1] > 57 ||
					num_voo[2] < 48 || num_voo[2] > 57 || num_voo[3] < 48 || num_voo[3] > 57 ||
					num_voo[4] != NULL)
			{
				if (strcmp(num_voo, "MENU") == 0)
				{
					return 0;
				}
				printf(" Favor inserir um voo valido!\n\n");
			}
			else
			{
				validador_voo = 1;
			}

			if (validador_voo == 1)
			{
				if (proc_voo(num_voo) == 0)
				{
					printf(" Voo nao encontrado, favor tentar novamente\n\n");
					validador_voo = 0;
				}
			}

			if (validador_voo == 1)
			{
				if (cad_reserva(num_voo, CPF, num_reserva, 1) == 3)
				{
					printf(" Infelizmente esse voo se encontra lotado no momento\n\n");
					validador_voo = 0;
				}
				else if (cad_reserva(num_voo, CPF, num_reserva, 1) == 4)
				{
					printf(" Passageiro ja cadastrado neste voo\n\n");
					validador_voo = 0;
				}
				else if (cad_reserva(num_voo, CPF, num_reserva, 1) == 5)
				{
					printf(" Infelizmente este voo esta cancelado\n\n");
					validador_voo = 0;
				}
			}
		}
		int escolha = 0;

		clear();
		printf("===============================================================\n\n");
		printf("                      CADASTRAR RESERVA \n\n\n");
		proc_voo(num_voo, 2);

		printf("\n Deseja cadastrar o CPF %s com\n", CPF);
		printf(" a reserva GB-%s nesse voo?\n\n", num_reserva);
		printf(" 1- Sim, desejo cadastrar e voltar ao menu principal\n");
		printf(" 2- Sim, desejo cadastrar nesse voo e em outro\n");
		printf(" 3- Nao, quero voltar ao menu principal\n");
		printf(" 4- Nao, quero cadastrar em outro\n\n");

		int validador_escolha = 0;
		while (validador_escolha == 0)
		{
			printf(" Escolha: ");
			scanf("%d", &escolha);

			if (escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4)
			{
				printf(" Favor escolhar uma opcao válida\n\n");
			}
			else
			{
				validador_escolha = 1;
			}
		}

		if (escolha == 1 || escolha == 2)
		{
			cad_reserva(num_voo, CPF, num_reserva, 0);
			if (escolha == 1)
			{
				validacao_cadastro = 1;
				return 0;
			}
		}
		else
		{
			if (escolha == 3)
			{
				validacao_cadastro = 1;
				return 0;
			}
		}
	}
}

int opcao_3()	// CONSULTAR VOO
{
	int valida_consulta = 0;
	char num_consulta[5];
	int escolha = 0;

	while (valida_consulta == 0)
	{
		system("cls");
		printf("===============================================================\n\n");
		printf("                        CONSULTAR VOO \n\n");

		printf(" Obs: Caso queira voltar ao menu basta digitar 'MENU'\n");
		printf("---------------------------------------------------------------\n\n");
		printf(" Voo a ser consultado: JEB-");
		scanf("%s", num_consulta);
		printf("\n\n");

		if (strcmp(num_consulta, "MENU") == 0)
		{
			return 0;
		}

		printf("===============================================================\n\n");

		if (proc_voo(num_consulta, 1) == 1)
		{
			printf("\n ===============================================================\n");
			printf("\n Gostaria de consultar outro voo?\n\n");
			printf(" 1- Sim\n");
			printf(" 2- Nao, quero voltar ao menu inicial\n\n");
		}
		else
		{
			printf("\n Voo nao encontrado, gostaria de consultar outro voo?\n\n");
			printf(" 1- Sim\n");
			printf(" 2- Nao, quero voltar ao menu inicial\n\n");
		}

		int valida_escolha = 0;
		while(valida_escolha == 0)
		{
			printf(" Escolha: ");
			scanf("%d", &escolha);
			if (escolha == 1 || escolha == 2)
			{
				if (escolha == 2)
				{
					valida_consulta = 1;
				}
				else
				{
					valida_consulta = 0;
				}
				valida_escolha = 1;
			}
			else
			{
				printf("\n Favor escolher uma opcao valida!\n\n");
			}
		}
	}
	return 0;
}

int opcao_4()	// CONSULTAR RESERVA
{
	int valida_consulta = 0;
	char num_consulta[tam_reserva];

	while (valida_consulta == 0)
	{
		system("cls");
		printf("===============================================================\n\n");
		printf("                       CONSULTAR RESERVA \n\n");

		printf(" Obs: Caso queira voltar ao menu basta digitar 'MENU'\n");
		printf("---------------------------------------------------------------\n\n");

		int valida_reserva = 0;
		while (valida_reserva == 0)
		{
			printf(" Reserva a ser consultada: GB-");
			scanf("%s", num_consulta);
			printf("\n");

			if (strcmp(num_consulta, "MENU") == 0)
			{
				return 0;
			}

			if (proc_reserva(num_consulta, 1) == 0)
			{
				printf(" Reserva nao encontrada, gostaria de consultar outra?\n\n");
				printf(" 1- Sim\n");
				printf(" 2- Nao, quero voltar ao menu inicial\n\n");
			}
			else
			{
				printf(" Deseja consultar outra reserva?\n\n");
				printf(" 1- Sim\n");
				printf(" 2- Nao, quero voltar ao menu inicial\n\n");
			}
			int escolha;
			int valida_escolha = 0;
			while (valida_escolha == 0)
			{
				printf(" Escolha: ");
				scanf("%d", &escolha);

				if (escolha != 1 && escolha != 2)
				{
					printf(" Favor escolher uma opcao valida\n\n");
				}
				else
				{
					if (escolha == 2)
					{
						return 0;
					}
					else
					{
						valida_escolha = 1;
						valida_reserva = 1;
					}
				}
			}
		}
	}
}

int opcao_5()	// CONSULTAR PASSAGEIRO
{
	int valida_consulta = 0;
	char num_consulta[tam_cpf];

	while (valida_consulta == 0)
	{
		system("cls");
		printf("===============================================================\n\n");
		printf("                       CONSULTAR PASSAGEIRO \n\n");

		printf(" Obs: Caso queira voltar ao menu basta digitar 'MENU'\n");
		printf("---------------------------------------------------------------\n\n");

		int valida_reserva = 0;
		while (valida_reserva == 0)
		{
			printf(" CPF (XXXXXXXXXXX): ");
			scanf("%s", num_consulta);
			printf("\n");

			if (strcmp(num_consulta, "MENU") == 0)
			{
				return 0;
			}

			if (proc_passageiro(num_consulta, 0) == 0)
			{
				printf(" Passageiro nao encontrado\n\n");
			}
			else
			{
				printf("------------------------- PASSAGEIRO -------------------------\n\n");
				proc_passageiro(num_consulta, 1);
				proc_cadastros(num_consulta);
				valida_reserva = 1;
			}
		}

		int escolha;
		int valida_escolha = 0;
		printf("===============================================================\n\n");
		printf(" Deseja consultar outro passageiro?\n\n");
		printf(" 1- Sim, desejo consultar\n");
		printf(" 2- Nao, desejo voltar ao menu inicial\n\n");

		while (valida_escolha == 0)
		{
			printf(" Escolha: ");
			scanf("%d", &escolha);

			if (escolha != 1 && escolha != 2)
			{
				printf(" Favor escolher uma opcao valida\n\n");
			}
			else
			{
				valida_escolha = 1;
				if (escolha == 2)
				{
					valida_consulta = 1;
				}
			}
		}
	}

	return 0;
}

int opcao_6()	// CANCELAR VOO
{
	int valida_cancelamento = 0;
	char num_consulta[tam_voo];

	while (valida_cancelamento == 0)	// Repete a operacao
	{
		system("cls");
		printf("===============================================================\n\n");
		printf("                         CANCELAR VOO \n\n");

		printf(" Obs: Caso queira voltar ao menu basta digitar 'MENU'\n");
		printf("---------------------------------------------------------------\n\n");

		int valida_voo = 0;
		while (valida_voo == 0)	// Valida se esta correto
		{
			printf(" Numero do voo (JEB-XXXX): JEB-");
			scanf("%s", num_consulta);

			if (strcmp(num_consulta, "MENU") == 0)
			{
				return 0;
			}

			if (proc_voo(num_consulta, 4) != 2)
			{
				printf("\n ===============================================================\n\n");

				int valida_escolha = 0;
				if (proc_voo(num_consulta, 1) == 1)
				{
					printf("\n ===============================================================\n");
					printf("\n Deseja cancelar esse voo e todas as reservas atribuidas a ele?\n\n");
					printf(" 1- Sim, desejo cancelar\n");
					printf(" 2- Nao, quero cancelar outro voo\n\n");
				}
				else
				{
					printf("\n Voo nao encontrado\n\n");
					valida_escolha = 1;
				}

				int escolha;
				while(valida_escolha == 0)
				{
					printf(" Escolha: ");
					scanf("%d", &escolha);
					if (escolha == 1 || escolha == 2)
					{
						if (escolha == 2)
						{
							valida_cancelamento = 0;
							valida_voo = 1;
						}
						else
						{
							cancela_voo(num_consulta);
							repassar();
							valida_cancelamento = 1;
							valida_voo = 2;

							printf("\n Voo Cancelado com sucesso!\n\n");
						}
						valida_escolha = 1;
					}
					else
					{
						printf("\n Favor escolher uma opcao valida!\n\n");
					}
				}
			}
			else
			{
				printf("\n Este voo ja se encontra cancelado\n\n");
			}
		}

		if (valida_voo == 2)
		{
			int validador_escolha = 0;
			int escolha;
			printf(" Deseja consultar outra reserva?\n\n");
			printf(" 1- Sim, desejo consultar\n");
			printf(" 2- Nao, quero voltar ao menu inicial\n\n");

			while (validador_escolha == 0)
			{
				printf(" Escolha: ");
				scanf("%d", &escolha);

				if (escolha == 2)
				{
					return 0;
				}
				else if (escolha == 1)
				{
					validador_escolha = 1;
					valida_voo = 1;
					valida_cancelamento = 0;
				}
			}
		}
	}
	return 0;
}

int opcao_7()	// CANCELAR RESERVA
{
	int validador_reserva = 0;
	while (validador_reserva == 0)
	{
		char num_comparador[tam_reserva];

		system("cls");
		printf("===============================================================\n\n");
		printf("                       CANCELAR RESERVA \n\n");

		printf(" Obs: Caso queira voltar ao menu basta digitar 'MENU'\n");
		printf("---------------------------------------------------------------\n\n");

		int validador_num = 0;
		while (validador_num == 0)
		{
			printf(" Reserva (GB-XXXXXX): GB-");
			scanf("%s", num_comparador);
			printf("\n");

			if (strcmp(num_comparador, "MENU") == 0)
			{
				return 0;
			}
			if (proc_reserva(num_comparador, 1) == 0)
			{
				printf("\n Reserva nao encontrada\n\n");
			}
			else if (proc_reserva(num_comparador, 2) == 2)
			{
				printf(" Essa reserva ja esta cancelada\n\n");
				validador_num = 1;
			}
			else
			{
				validador_num = 1;
				int validador_escolha = 0;
				int escolha;
				printf(" Tem certeza que deseja cancelar essa reserva?\n\n");
				printf(" 1- Sim, desejo cancela-la\n");
				printf(" 2- Nao, quero consultar outra\n\n");

				while (validador_escolha == 0)
				{
					printf(" Escolha: ");
					scanf("%d", &escolha);

					if (escolha == 1)
					{
						validador_escolha = 1;
						repassar();
						printf("\n Reserva cancelada com sucesso\n\n");
						getc(stdin);
					}
					else if (escolha == 2)
					{
						validador_escolha = 1;
						validador_num = 2;
					}
				}
			}
		}
		if (validador_num == 1)
		{
			int validador_escolha = 0;
			int escolha;
			printf(" Deseja consultar outra reserva?\n\n");
			printf(" 1- Sim, desejo consultar\n");
			printf(" 2- Nao, quero voltar ao menu inicial\n\n");

			while (validador_escolha == 0)
			{
				printf(" Escolha: ");
				scanf("%d", &escolha);

				if (escolha == 2)
				{
					return 0;
				}
				else if (escolha == 1)
				{
					validador_escolha = 1;
				}
			}
		}

	}
}

int opcao_8()	// EXCLUIR VOO
{
	int validador_reserva = 0;
	while (validador_reserva == 0)
	{
		char escolha[tam_excluir];
		int valida_escolha = 0;
		char num_comparador[tam_reserva];

		system("cls");
		printf("===============================================================\n\n");
		printf("                        EXCLUIR VOO \n\n");

		printf(" Obs: Caso queira voltar ao menu basta digitar 'MENU'\n");
		printf("---------------------------------------------------------------\n\n");

		int validador_num = 0;
		while (validador_num == 0)
		{
			printf(" Numero do voo (JEB-XXXX): JEB-");
			scanf("%s", num_comparador);
			printf("\n---------------------------------------------------------------\n\n");

			if (strcmp(num_comparador, "MENU") == 0)
			{
				return 0;
			}

			if (proc_voo(num_comparador, 1) == 0)
			{
				printf(" Voo nao encontrado\n\n");
			}
			else
			{
				validador_num = 1;
			}
		}

		printf("\n Tem certeza que deseja excluir esse voo e todas as reservas atribuidas a ele?\n\n");
		printf(" :: Caso deseje excluir digite por extenso: 'EXCLUIR'\n");
		printf(" :: Caso deseje procurar outro voo basta digitar: '2'\n\n");

		while (valida_escolha == 0)
		{
			printf(" Escolha: ");
			scanf("%s", escolha);
			printf("\n");

			if (strcmp(escolha, "EXCLUIR") == 0)
			{
				valida_escolha = 1;
				validador_reserva = 1;
				proc_voo(num_comparador, 3);
				backup();
				repassar();
			}
			else if (escolha[0] == 50) // escolha = 2
			{
				valida_escolha = 2;
			}
			else
			{
				printf(" Favor digitar corretamente o que deseja\n\n");
			}
		}

		if (valida_escolha == 1)
		{
			printf("\n Voo e reservas excluidas com sucesso\n\n");
			printf(" Deseja consultar outro voo?\n\n");
			printf(" 1- Sim, quero consultar\n");
			printf(" 2- Nao, quero voltar ao menu principal\n\n");
		}
		while (valida_escolha == 1)
		{
			printf(" Escolha: ");
			scanf("%s", escolha);

			if (escolha[0] == 49 && escolha[1] == NULL)
			{
				valida_escolha = 2;
				validador_reserva = 0;
			}
			else if (escolha[0] == 50 && escolha[1] == NULL)
			{
				valida_escolha = 2;
				validador_reserva = 1;
			}
			else
			{
				printf(" Favor escolher uma opcao valida\n\n");
			}
		}
	}
	return 0;
}

void arq_voo(num, max, dia, mes, ano, hora, min) // Salva o Voo em arquivo
{
	FILE *file;
	file = fopen("Arquivo Voo.txt", "a");

	if (file == NULL)
	{
		file = fopen("Arquivo Voo.txt", "w");
		file = fopen("Arquivo Voo.txt", "a");
	}

	fprintf(file, "==============================================================\n\n");
	fprintf(file, " Numero do voo: JEB-%s\n", num);
	fprintf(file, " Data: %02d/%02d/%04d - %02d:%02d\n", dia, mes, ano, hora, min);
	fprintf(file, " Ocupacao: 000/%03d - 00.00\n", max);
	fprintf(file, " Situacao: Ativo\n\n");
	fclose(file);
}

int proc_voo(comparador, imprimir)	// Procura se o voo ja existe, imprimir == 1 imprime o voo || == 2 imprime o voo e as reservas
{
//	printf(" Comparador: %s\n\n", comparador);
//	system("pause");

	char num[tam_voo - 1];
	int igual = 0;

	FILE *file;
	file = fopen("Arquivo Voo.txt", "r");

	if (file == NULL)	// Testa se o arquivo existe
	{
		file = fopen("Arquivo Voo.txt", "w");
		file = fopen("Arquivo Voo.txt", "r");
	}

	char linha[tam_linha];
	int finalizador = 0;
	int a;
	int cont = 0;
	int cont_voo;
	int primeiro = 0;

	while(finalizador == 0 && fgets(linha, tam_linha, file) != NULL)
	{
		//	printf("\nProcurando... ");
		for (a = 1; a < tam_linha; a++)
		{
			// Procura por "JEB-"
			if (linha[a] == 74 && linha[a + 1] == 69 && linha[a + 2] == 66 && linha[a + 3] == 45)
			{
				num[0] = linha[a + 4];
				num[1] = linha[a + 5];
				num[2] = linha[a + 6];
				num[3] = linha[a + 7];

				//	printf("\n\n Achei um voo: JEB-%s\n\n", num);
				//	printf(" Comparador: %s\n\n", comparador);
				//	system("pause");

				if (strcmp(comparador, num) == 0)
				{
					//	printf(" Elas sao iguais!\n");
					finalizador = 1;
					igual = 1;
					cont_voo = cont;

					if (imprimir == 1)
					{
						printf("%s", linha);

						while (fgets(linha, tam_linha, file) != NULL && linha[1] != 61)
						{
							if (linha[1] == 79 && linha[26] != 48)
							{
								linha[26] = 37;
								printf("%s\n", linha);
							}
							else if (linha[1] == 79 && linha[26] == 48)
							{
								linha[27] = 37;
								printf("%s\n", linha);
							}
							else
							{
								printf("%s", linha);
							}
						}
					}
					else if (imprimir == 2)
					{
						printf("%s", linha);

						while(fgets(linha, tam_linha, file) != NULL && linha[1] != 61 && linha[1] != 45)
						{
							if (linha[1] == 79 && linha[30] != 35)
							{
								linha[26] = 37;
								printf("%s\n", linha);
							}
							else if (linha[1] == 79 && linha[30] == 35)
							{
								linha[27] = 37;
								printf("%s\n", linha);
							}
							else
							{
								printf("%s", linha);
							}
						}
					}
					else if (imprimir == 3)
					{
						exclui_voo(cont_voo);
					}
				}
			}
		}
		if (imprimir == 4 && igual == 1)
		{
			//	printf(linha);
			//	printf("\n");
			//	system("pause");
			finalizador = 0;

			if (linha[1] == 83 && linha[11] == 67 && primeiro == 0)
			{
				fclose(file);
				return 2;
			}
			if (linha[1] == 45 || linha[1] == 61)
			{
				finalizador = 1;
				primeiro = 1;
			}
		}
		cont = cont + 1;
	}

	fclose(file);
	if (igual == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int cad_reserva(comparador, cpf, gb, testar_lotacao) // Cadastra reserva em arquivo e testa se o voo esta lotado
{
//	clear();

//	printf(" La vamos nos!!\n\n");

	char num[tam_voo - 1];
	int igual = 0;

	FILE *file;
	file = fopen("Arquivo Voo.txt", "r");

//	printf(" Arquivo Voo aberto com sucesso!\n\n");

	FILE *file_temp;
	file_temp = fopen("Arquivo Voo temp.txt", "w");
	file_temp = fopen("Arquivo Voo temp.txt", "a");

//	printf(" Arquivo Voo Temp aberto com sucesso!\n\n");

	char linha[tam_linha];
	int finalizador = 0;
	int a;
	int lotado = 0;
	int primeiro = 0;

//	printf(" Vou comecar a procurar pelo voo JEB-%s e depois gravar no arquivo temporario\n\n", comparador);

//	getchar();
	while(fgets(linha, tam_linha, file) != NULL)
	{
		//	printf(" Procurando...\n");
		//	printf("%s", linha);
		for (a = 1; a < tam_linha; a++)
		{
			// Procura por "JEB-"
			if (linha[a] == 74 && linha[a + 1] == 69 && linha[a + 2] == 66 && linha[a + 3] == 45)
			{
				num[0] = linha[a + 4];
				num[1] = linha[a + 5];
				num[2] = linha[a + 6];
				num[3] = linha[a + 7];

				//	printf("\n Achei o voo JEB-%s\n\n", num);

				if (strcmp(comparador, num) == 0)
				{
					//	printf(" Ele eh igual ao que estavamos procurando!!\n\n");
					finalizador = 1;
					igual = 1;
					fprintf(file_temp, linha);

					if (proc_cpf(comparador, cpf) == 1)
					{
						//	printf(" Ja esta cadastrado\n");
						//	system("pause");
						fclose(file);
						fclose(file_temp);
						remove(file_temp);
						return 4;
					}

					//	printf(" Vou gravar no Arquivo temporario o voo que achei!!!\n\n");

					float passageiros;
					int total;
					float porcentagem;
					int limitador = 0;

					while(fgets(linha, tam_linha, file) != NULL && linha[1] != 61)
					{
						if (linha[1] == 45)
						{
							limitador = 1;
						}
						if (linha[1] == 83 && linha[11] == 67 && limitador == 0)
						{
							return 5;
						}
						if (linha[1] == 79 && linha[26] != 48)
						{
							passageiros = (linha[11] - 48) * 100 + (linha[12] - 48) * 10 + linha[13] - 48;
							passageiros = passageiros + 1;

							total = (linha[15] - 48) * 100 + (linha[16] - 48) * 10 + linha[17] - 48;

							porcentagem = (passageiros / total) * 100;

							if (passageiros - 1 == total)
							{
								//	printf(" Porcentagem = 100");
								//	system("pause");
								fclose(file_temp);
								remove("Arquivo Voo temp.txt");
								return 3;
							}

							//	printf(" \n passageiros; %f\n", passageiros);
							//	printf(" \n total; %d\n", total);
							//	printf(" \n porcentagem; %f\n", porcentagem);

							int inteiro = passageiros;
							linha[11] = inteiro / 100 + 48;
							linha[12] = (inteiro / 10) % 10 + 48;
							linha[13] = inteiro % 10 + 48;

							if (passageiros != total)
							{
								inteiro = porcentagem * 100;
								linha[21] = inteiro / 1000 + 48;
								linha[22] = (inteiro / 100) % 10 + 48;
								linha[24] = (inteiro / 10) % 10 + 48;
								linha[25] = inteiro % 10 + 48;
							}
							else
							{
								// 100.00%
								linha[21] = 49;
								linha[22] = 48;
								linha[23] = 48;
								linha[24] = 46;
								linha[25] = 48;
								linha[26] = 48;
								lotado = 1;
							}
						}
						else if (linha[26] == 48 && lotado == 0)
						{
							//	printf(" Carac 26 == 48 e lotado == 0");
							//	system("pause");
							fclose(file_temp);
							remove("Arquivo Voo temp.txt");
							return 3;
						}

						if (lotado == 1 && primeiro == 0)
						{
							fprintf(file_temp, "%s\n", linha);
							primeiro = 1;
						}
						else
						{
							fprintf(file_temp, linha);
						}
					}
					//	printf("\n Agora vou gravar os dados do passageiro\n\n");
					fprintf(file_temp, "--------------------------------------------------------------\n\n");
					fprintf(file_temp, " CPF: %s\n", reserva.cpf);
					fprintf(file_temp, " Reserva: GB-%s\n", gb);
					fprintf(file_temp, " Situacao: Ativa\n\n");
				}
			}
		}
		fprintf(file_temp, linha);
	}

//	printf(" Terminei de gravar no arquivo temp!!\n");

	fclose(file);
	fclose(file_temp);

	if (igual == 1 && testar_lotacao != 1)
	{
		repassar();
		return 1;
	}
	else
	{
		remove("Arquivo Voo temp.txt");
		return 0;
	}
}

int proc_reserva(comparador, imprimir) // Procura a reserva e manda imprimir caso imprimir == 1
{
	char num[tam_reserva - 1];
	int igual = 0;

	FILE *file;
	file = fopen("Arquivo Voo.txt", "r");

	if (file == NULL)	// Testa se o arquivo existe
	{
		file = fopen("Arquivo Voo.txt", "w");
		file = fopen("Arquivo Voo.txt", "r");
	}

	char linha[tam_linha];
	int finalizador = 0;
	int a;
	int cont = 0;
	int cont_voo = 0;
	int cont_reserva = 0;

	while(finalizador == 0 && fgets(linha, tam_linha, file) != NULL)
	{
		cont = cont + 1;
		for (a = 1; a < tam_linha; a++)
		{
			// Procura por "JEB-"
			if (linha[a] == 74 && linha[a + 1] == 69 && linha[a + 2] == 66 && linha[a + 3] == 45)
			{
				cont_voo = cont;
			}
			// Procura por "GB-"
			if (linha[a] == 71 && linha[a + 1] == 66 && linha[a + 2] == 45)
			{
				cont_reserva = cont;
				num[0] = linha[a + 3];
				num[1] = linha[a + 4];
				num[2] = linha[a + 5];
				num[3] = linha[a + 6];
				num[4] = linha[a + 7];
				num[5] = linha[a + 8];

				if (strcmp(comparador, num) == 0)
				{
					finalizador = 1;
					igual = 1;

					if (imprimir == 1)
					{
						fclose(file);
						imprime_reserva(cont_voo, cont_reserva);
						return 1;
					}
					else if (imprimir == 2)
					{
						fclose(file);
						if (cancela_reserva(cont_voo, cont_reserva) == 10)
						{
							return 2;
						}
						else
						{
							return 1;
						}
					}
				}
			}
		}
	}
	fclose(file);
	if (igual == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int imprime_reserva(cont_voo, cont_reserva) // Imprime a reserva e o voo em que foi cadastrada
{
	char num[tam_reserva - 1];
	int igual = 0;

	FILE *file;
	file = fopen("Arquivo Voo.txt", "r");

	if (file == NULL)	// Testa se o arquivo existe
	{
		file = fopen("Arquivo Voo.txt", "w");
		file = fopen("Arquivo Voo.txt", "r");
	}

	char linha[tam_linha];
	int finalizador = 0;
	int a;
	int cont = 0;
	int imprimir_voo = 0;
	int imprimir_reserva = 0;
	int pv = 0;
	int pr = 0;
	char cpf[tam_cpf];

	while(finalizador == 0 && fgets(linha, tam_linha, file) != NULL)
	{
		cont = cont + 1;

		if (cont == cont_voo || imprimir_voo == 1)
		{
			imprimir_voo = 1;

			if (pv == 0)
			{
				printf("----------- VOO EM QUE FOI CADASTRADA -----------\n\n");
				pv = 1;
			}
			if (linha[1] != 45)
			{

				if (linha[1] == 79 && linha[26] != 48)
				{
					linha[26] = 37;
					printf("%s\n", linha);
				}
				else if (linha[1] == 79 && linha[26] == 48)
				{
					linha[27] = 37;
					printf("%s\n", linha);
				}
				else
				{
					printf("%s", linha);
				}
			}
			else
			{
				imprimir_voo = 0;
			}
		}
		if (cont == cont_reserva - 1)
		{
			printf("------------- RESERVA PERTENCENTE A -------------\n\n");//--
			cpf[0] = linha[6];
			cpf[1] = linha[7];
			cpf[2] = linha[8];
			cpf[3] = linha[9];
			cpf[4] = linha[10];
			cpf[5] = linha[11];
			cpf[6] = linha[12];
			cpf[7] = linha[13];
			cpf[8] = linha[14];
			cpf[9] = linha[15];
			cpf[10] = linha[16];

			proc_passageiro(cpf, 1);
		}
		if (cont == cont_reserva || imprimir_reserva == 1)
		{
			imprimir_reserva = 1;

			if(pr == 0)
			{
				printf("-------------------- RESERVA --------------------\n\n");
				pr = 1;
			}
			if (linha[1] != 45 && linha[1] != 61)
			{
				printf(linha);
			}
			else
			{
				imprimir_reserva = 0;
				finalizador = 1;
				printf("=================================================\n\n");
			}
		}
	}
	return 0;
}

int proc_cpf(comparador, cpf) // Procura pelo CPF no voo para n deixar uma pessoa se cadastrar no mesmo voo
{
	char num[tam_voo - 1];
	char num_cpf[tam_cpf];
	int igual = 0;

	FILE *file;
	file = fopen("Arquivo Voo.txt", "r");

	if (file == NULL)	// Testa se o arquivo existe
	{
		file = fopen("Arquivo Voo.txt", "w");
		file = fopen("Arquivo Voo.txt", "r");
	}

	char linha[tam_linha];
	int a;
	int finalizador = 0;

	while(finalizador == 0 && fgets(linha, tam_linha, file) != NULL)
	{
		for (a = 1; a < tam_linha; a++)
		{
			// Procura por "JEB-"
			if (linha[a] == 74 && linha[a + 1] == 69 && linha[a + 2] == 66 && linha[a + 3] == 45 && igual == 0)
			{
				num[0] = linha[a + 4];
				num[1] = linha[a + 5];
				num[2] = linha[a + 6];
				num[3] = linha[a + 7];

				//	printf(" %s\n", num);
				//	system("pause");

				if (strcmp(comparador, num) == 0)
				{
					//	printf(" Iguais\n");
					igual = 1;
				}
			}
			else if (igual == 1)
			{
				if (linha[1] == 61)
				{
					fclose(file);
					return 0;
				}

				// Procura por "CPF:"
				if (linha[a] == 67 && linha[a + 1] == 80 && linha[a + 2] == 70 && linha[a + 3] == 58)
				{
					num_cpf[0] = linha[a + 5];
					num_cpf[1] = linha[a + 6];
					num_cpf[2] = linha[a + 7];
					num_cpf[3] = linha[a + 8];
					num_cpf[4] = linha[a + 9];
					num_cpf[5] = linha[a + 10];
					num_cpf[6] = linha[a + 11];
					num_cpf[7] = linha[a + 12];
					num_cpf[8] = linha[a + 13];
					num_cpf[9] = linha[a + 14];
					num_cpf[10] = linha[a + 15];

					//	printf(" Num_cpf: %s\n", num_cpf);
					//	printf(" CPF: %s\n", cpf);
					//	system("pause");

					if (strcmp(cpf, num_cpf) == 0)
					{
						//	printf(" Cpf sao iguais\n");
						//	system("pause");
						finalizador = 1;
						fclose(file);
						return 1;
					}
				}
			}
		}
	}
	fclose(file);
	return 0;
}

void repassar() // Repassa tudo do "Arquivo Voo temp.txt" para o "Arquivo Voo.txt"
{
	FILE *file;
	file = fopen("Arquivo Voo.txt", "w");
	file = fopen("Arquivo Voo.txt", "a");

	FILE *file_temp;
	file_temp = fopen("Arquivo Voo temp.txt", "r");

	char linha[tam_linha];
	int a;

	while (fgets(linha, tam_linha, file_temp) != NULL)
	{
		fprintf(file, linha);
	}

	fclose(file);
	fclose(file_temp);
	remove("Arquivo Voo temp.txt");
}

void arq_passageiro(cpff, nome, sexo, dia, mes, ano) // Salva os dados do passageiro em arquivo
{
	FILE *file;
	file = fopen("Arquivo Passageiros.txt", "a");

	if (file == NULL)
	{
		file = fopen("Arquivo Passageiros.txt", "w");
		file = fopen("Arquivo Passageiros.txt", "a");
	}



	fprintf(file, "==============================================================\n\n");
	fprintf(file, " CPF: %s \n", cpff);
	fprintf(file, " Nome: %s \n", nome);


	if (reserva.sexo == 1)
	{
		fprintf(file, " Sexo: Masculino\n");
	}
	else if (reserva.sexo == 2)
	{
		fprintf(file, " Sexo: Feminino\n");
	}
	else
	{
		fprintf(file, " Sexo: Prefere nao informar\n");
	}

	fprintf(file, " Data de nascimento: %02d/%02d/%04d\n\n", dia, mes, ano);
	fclose(file);
}

int proc_passageiro(comparador, imprimir) // Procura e imprime pelo passageiro caso imprimir == 1
{
	char num[tam_cpf - 1];
	int igual = 0;

	FILE *file;
	file = fopen("Arquivo Passageiros.txt", "r");

	if (file == NULL)	// Testa se o arquivo existe
	{
		file = fopen("Arquivo Passageiros.txt", "w");
		file = fopen("Arquivo Passageiros.txt", "r");
	}

	char linha[tam_linha];
	int finalizador = 0;
	int a;
	int pos;
	int cont = 0;

	while(finalizador == 0 && fgets(linha, tam_linha, file) != NULL)
	{
//		printf("\nProcurando... ");
		cont = cont + 1;
		for (a = 1; a < tam_linha; a++)
		{
			// Procura por "CPF:"
			if (linha[a] == 67 && linha[a + 1] == 80 && linha[a + 2] == 70 && linha[a + 3] == 58)
			{
				num[0] = linha[a + 5];
				num[1] = linha[a + 6];
				num[2] = linha[a + 7];
				num[3] = linha[a + 8];
				num[4] = linha[a + 9];
				num[5] = linha[a + 10];
				num[6] = linha[a + 11];
				num[7] = linha[a + 12];
				num[8] = linha[a + 13];
				num[9] = linha[a + 14];
				num[10] = linha[a + 15];

//				printf("\n\n Achei um CPF: %s\n", num);
//				printf(" Comparador de CPF: %s\n", comparador);

				if (strcmp(comparador, num) == 0)
				{
//					printf(" Elas sao iguais!\n");
					finalizador = 1;
					igual = 1;

					if (imprimir == 1)
					{
						printf("%s", linha);

						while(fgets(linha, tam_linha, file) != NULL && linha[1] != 61)
						{
							printf("%s", linha);
						}
					}
				}
			}
		}
	}
	if (igual == 1)
	{
		fclose(file);
		return 1;
	}
	else
	{
		fclose(file);
		return 0;
	}
}

int proc_cadastros(comparador) // Procura pelas reservas feitas por um passageiro e imprime
{
	char cpf_cad[tam_cpf - 1];
	int igual = 0;

	FILE *file;
	file = fopen("Arquivo Voo.txt", "r");

	if (file == NULL)	// Testa se o arquivo existe
	{
		file = fopen("Arquivo Voo.txt", "w");
		file = fopen("Arquivo Voo.txt", "r");
	}

	char linha[tam_linha];
	int finalizador = 0;

	char salvar[tam_voo - 1];
	char voo_cadastrado[tam_linha];

	while(finalizador == 0 && fgets(linha, tam_linha, file) != NULL)
	{
		// Procura por "JEB-"
		if (linha[16] == 74 && linha[17] == 69 && linha[18] == 66 && linha[19] == 45)
		{
			salvar[0] = linha[20];
			salvar[1] = linha[21];
			salvar[2] = linha[22];
			salvar[3] = linha[23];

			//	printf(" voo_cadastrado: %s\n\n", voo_cadastrado);
			//	printf(" salvar: %s\n\n", salvar);
			//	system("pause");
		}
		// Procura por "CPF"
		if (linha[1] == 67 && linha[2] == 80 && linha[3] == 70)
		{
			//	printf(" Voo antes: %s\n\n", voo_cadastrado);

			cpf_cad[0] = linha[6];
			cpf_cad[1] = linha[7];
			cpf_cad[2] = linha[8];
			cpf_cad[3] = linha[9];
			cpf_cad[4] = linha[10];
			cpf_cad[5] = linha[11];
			cpf_cad[6] = linha[12];
			cpf_cad[7] = linha[13];
			cpf_cad[8] = linha[14];
			cpf_cad[9] = linha[15];
			cpf_cad[10] = linha[16];

			//	printf(" Voo depois: %s\n\n", voo_cadastrado);

			//	printf(" Achei o CPF: %s\n\n", cpf_cad);
			//	system("pause");

			if (strcmp(comparador, cpf_cad) == 0)	//                                      ;
			{
				igual = 1;
				printf("--------------------- VOO E SUA RESERVA ----------------------\n\n");

				//	printf(" salvar: %s\n\n", salvar);

				voo_cadastrado[0] = salvar[0];
				voo_cadastrado[1] = salvar[1];
				voo_cadastrado[2] = salvar[2];
				voo_cadastrado[3] = salvar[3];

				//	printf(" voo_cadastrado: %s\n\n", voo_cadastrado);
				//	system("pause");
				proc_voo(voo_cadastrado, 2);
			}
		}

		if (igual == 1 || igual == 2)
		{
			if (linha[1] == 61 || linha[1] == 45)
			{
				igual = 0;
			}
			else if (igual == 2)
			{
				printf(linha);
			}
			else if (igual == 1)
			{
				igual = 2;
			}
		}
	}
	fclose(file);
	return 0;
}

int cancela_voo(comparador) // Cancela o Voo e todas as reservas
{
	char voo_cadastrado[tam_linha + 1];
	char salvar[tam_voo - 1];
	char cpf_cad[tam_cpf - 1];
	int igual = 0;

	char linha[tam_linha];
	int finalizador = 0;

	int primeiro = 0;
	int printado = 0;
	int a;


	FILE *file;
	file = fopen("Arquivo Voo.txt", "r");

	if (file == NULL)
	{
		file = fopen("Arquivo Voo.txt", "w");
		file = fopen("Arquivo Voo.txt", "r");
	}

	FILE *file_temp;
	file_temp = fopen("Arquivo Voo temp.txt", "w");
	file_temp = fopen("Arquivo Voo temp.txt", "a");

	while(finalizador == 0 && fgets(linha, tam_linha, file) != NULL)
	{
		// Procura por "JEB-"
		if (linha[16] == 74 && linha[17] == 69 && linha[18] == 66 && linha[19] == 45)
		{
			salvar[0] = linha[20];
			salvar[1] = linha[21];
			salvar[2] = linha[22];
			salvar[3] = linha[23];
			//	printf(" Salvar: %s\n\n", salvar);
			//	system("pause");
		}

		//	printf(" voo_cadastrado antes: %s\n\n", voo_cadastrado);
		//	printf(" salvar antes: %s\n\n", salvar);
		//	system("pause");

		//	voo_cadastrado[0] = salvar[0];
		//	voo_cadastrado[1] = salvar[1];
		//	voo_cadastrado[2] = salvar[2];
		//	voo_cadastrado[3] = salvar[3];

		//	printf(" voo_cadastrado: %s\n\n", voo_cadastrado);
		//	printf(" salvar: %s\n\n", salvar);
		//	system("pause");

		if (strncmp(comparador, salvar, 3) == 0)	//                                      ;
		{
			igual = 1;
		}
		else
		{
			igual = 0;
		}

		if (igual == 1)
		{
			if (linha[1] == 83)
			{
				if (primeiro == 0)
				{
					//	printf(" Vou printar que o voo esta cancelado!\n\n");
					fprintf(file_temp, " Situacao: Cancelado\n");
					printado = 1;
					primeiro = 1;
				}
				else
				{
					//	printf(" Vou printar que a reserva esta cancelada!\n\n");
					fprintf(file_temp, " Situacao: Cancelada\n");
					printado = 1;
				}
			}
		}
		if (printado == 0)
		{
			fprintf(file_temp, linha);
		}
		else
		{
			//	printf(" Nao vou printar a linha\n\n");
			printado = 0;
		}
	}
	fclose(file);
	fclose(file_temp);
//	system("pause");
	return 0;
}

int cancela_reserva(cont_voo, cont_reserva)	// Cancela a reserva e subtrai da ocupacao do voo
{
	int cont = 0;
	int imprimir = 0;
	char linha[tam_linha];
	int primeiro = 0;

	FILE *file;
	file = fopen("Arquivo Voo.txt", "r");

	if (file == NULL)
	{
		file = fopen("Arquivo Voo.txt", "w");
		file = fopen("Arquivo Voo.txt", "r");
	}

	FILE *file_temp;
	file_temp = fopen("Arquivo Voo temp.txt", "w");
	file_temp = fopen("Arquivo Voo temp.txt", "a");

	while(fgets(linha, tam_linha, file) != NULL)
	{
		if(cont == cont_voo || imprimir == 1)
		{
			fprintf(file_temp, linha);

			float passageiros;
			int total;
			float porcentagem;

			while(fgets(linha, tam_linha, file) != NULL && linha[1] != 61)
			{
				cont = cont + 1;
				if (linha[1] == 79)
				{
					passageiros = (linha[11] - 48) * 100 + (linha[12] - 48) * 10 + linha[13] - 48;
					passageiros = passageiros - 1;

					total = (linha[15] - 48) * 100 + (linha[16] - 48) * 10 + linha[17] - 48;

					porcentagem = (passageiros / total) * 100;

					int inteiro = passageiros;
					linha[11] = inteiro / 100 + 48;
					linha[12] = (inteiro / 10) % 10 + 48;
					linha[13] = inteiro % 10 + 48;

					if (passageiros + 1 != total)
					{
						inteiro = porcentagem * 100;
						linha[21] = inteiro / 1000 + 48;
						linha[22] = (inteiro / 100) % 10 + 48;
						linha[24] = (inteiro / 10) % 10 + 48;
						linha[25] = inteiro % 10 + 48;
					}
					else
					{
						inteiro = porcentagem * 100;
						linha[21] = inteiro / 1000 + 48;
						linha[22] = (inteiro / 100) % 10 + 48;
						linha[23] = 46;
						linha[24] = (inteiro / 10) % 10 + 48;
						linha[25] = inteiro % 10 + 48;
						linha[26] = NULL;
						primeiro = 1;
						fprintf(file_temp, linha);
						fprintf(file_temp, "\n");
					}
				}
				if (cont == cont_reserva)
				{
					if (linha[11] == 65)
					{
						fprintf(file_temp, " Situacao: Cancelada\n");
					}
					else
					{
						fclose(file_temp);
						fclose(file);
						return 10;
					}
				}
				else
				{
					if (primeiro == 0)
					{
						fprintf(file_temp, linha);
					}
					else
					{
						primeiro = 0;
					}
				}
			}
		}
		fprintf(file_temp, linha);

		cont = cont + 1;
	}
	fclose(file_temp);
	fclose(file);
	return 0;
}

int exclui_voo(comparador) // Exclui os voos e as reservas vinculadas a ele
{
	FILE *file;
	file = fopen("Arquivo Voo.txt", "r");

	FILE *file_temp;
	file_temp = fopen("Arquivo Voo temp.txt", "w");
	file_temp = fopen("Arquivo Voo temp.txt", "a");

	char linha[tam_linha];
	int cont = 0;
	int validador = 0;

//	printf("\n Cheguei aqui!\n\n");
//	system("pause");
	while(fgets(linha, tam_linha, file) != NULL)
	{
		if (cont == comparador - 2 || validador == 1)
		{
		//	printf("\n Vou parar de imprimir\n\n");
		//	system("pause");
			validador = 1;
			if (linha[1] == 61 && cont > comparador)
			{
			//	printf("\n Vou imprimir dnv\n\n");
			//	system("pause");
				validador = 0;
				fprintf(file_temp, linha);
			}
		}
		else
		{
		//	printf("\n Estou imprimindo!!\n\n");
		//	system("pause");
			fprintf(file_temp, linha);
		}
		cont = cont + 1;
	}
	fclose(file);
	fclose(file_temp);
	return 0;
}

void backup()
{
	FILE *file;
	file = fopen("Arquivo Voo.txt", "r");

	FILE *file_backup;
	file_backup = fopen("backup ultimo voo excluido.txt", "w");
	file_backup = fopen("backup ultimo voo excluido.txt", "a");
	
	char linha[tam_linha];
	
	while(fgets(linha, tam_linha, file) != NULL)
	{
		fprintf(file_backup, linha);
	}
	fclose(file_backup);
	fclose(file);
}

int checagem_data(dia, mes, ano, hora, min, opcao)	// Valida a data e o horario || opcao = 1 é voo, = 2 é nascimento
{
	// OPCAO = 1: Para cadastrar data do voo
	// OPCAO = 2: Para cadastrar data de nascimento

	int validador_dia_01, validador_dia_02, validador_dia_03;
	int validador_mes, validador_ano;
	int validador_hora, validador_min;
	int soma;

	validador_dia_01 = 0;
	validador_dia_02 = 0;
	validador_dia_03 = 0;
	validador_mes = 0;
	validador_ano = 0;
	validador_hora = 0;
	validador_min = 0;

	struct tm *p;
	time_t seconds;

	time(&seconds);
	p = localtime(&seconds);

	int dia_hoje = p->tm_mday;
	int mes_hoje = p->tm_mon + 1;
	int ano_hoje = p->tm_year + 1900;
	int hora_agora = p->tm_hour;
	int min_agora = p->tm_min;

	int validador_dia_atual = 0;
	int validador_mes_atual = 0;
	int validador_ano_atual = 0;
	int validador_hora_atual = 0;
	int validador_min_atual = 0;

	if (opcao == 1)	// SOMA 6
	{
		if (ano > ano_hoje)
		{
			validador_dia_atual = 1;
			validador_mes_atual = 1;
			validador_ano_atual = 1;
			validador_hora_atual = 1;
			validador_min_atual = 1;
			validador_ano = 1;
		}
		else if (ano == ano_hoje)
		{
			validador_ano_atual = 1;
			validador_ano = 1;

			if (mes > mes_hoje)
			{
				validador_mes_atual = 1;
				validador_dia_atual = 1;
				validador_hora_atual = 1;
				validador_min_atual = 1;
			}
			else if (mes == mes_hoje)
			{
				validador_mes_atual = 1;

				if (dia > dia_hoje + 1)
				{
					validador_dia_atual = 1;
					validador_hora_atual = 1;
					validador_min_atual = 1;
				}
				else if (dia == dia_hoje + 1)
				{
					validador_dia_atual = 1;

					if (hora > hora_agora)
					{
						validador_hora_atual = 1;
						validador_min_atual = 1;
					}
					else if (hora == hora_agora)
					{
						validador_hora_atual = 1;

						if (min > min_agora)
						{
							validador_min_atual = 1;
						}
					}
				}
			}
		}
	}

	else if (opcao == 2)	// SOMA = 4
	{
		if (ano < ano_hoje)
		{
			validador_dia_atual = 1;
			validador_mes_atual = 1;
			validador_ano_atual = 1;
			validador_ano = 1;
		}
		else if (ano == ano_hoje)
		{
			validador_ano_atual = 1;
			validador_ano = 1;

			if (mes < mes_hoje)
			{
				validador_mes_atual = 1;
				validador_dia_atual = 1;
			}
			else if (mes == mes_hoje)
			{
				validador_mes_atual = 1;

				if (dia < dia_hoje + 1)
				{
					validador_dia_atual = 1;
				}
				else if (dia == dia_hoje + 1)
				{
					validador_dia_atual = 1;
				}
			}
		}
	}

	if ((ano % 4 == 0 & ano % 100 != 0) || (ano % 100 == 0 & ano % 400 == 0))	// SOMA = 2
	{
		if (mes == 2)	// Mês de Fev.
		{
			validador_mes = 1;
			if (dia > 0 & dia <= 29)	// Dia válido
			{
				validador_dia_01 = 1;
			}
		}
		else if (mes > 0 & mes <= 12)
		{
			validador_mes = 1;
			if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)	// Meses com dia até 31
			{
				if (dia > 0 & dia <= 31)  	// Dia válido
				{
					validador_dia_02 = 1;
				}
			}
			else if (dia > 0 & dia <= 30)  	// Dia válido
			{
				validador_dia_03 = 1;
			}
		}
	}
	else if (mes == 2)	// Mês de Fev.
	{
		validador_mes = 1;
		if (dia > 0 & dia <= 28)	// Dia válido
		{
			validador_dia_01 = 1;
		}
	}
	else if (mes > 0 & mes <= 12)
	{
		validador_mes = 1;
		if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)	// Meses com dia até 31
		{
			if (dia > 0 & dia <= 31)	// Dia válido
			{
				validador_dia_02 = 1;
			}
		}
		else if (dia > 0 & dia <= 30)	// Dia válido
		{
			validador_dia_03 = 1;
		}
	}


	if (opcao == 1)	// SOMA = 2
	{
		if (hora >= 0 & hora <= 23)	// Hora válida
		{
			validador_hora = 1;
		}
		if (min >= 0 & min <= 59)	// Min válido
		{
			validador_min = 1;
		}

		soma = validador_dia_01 + validador_dia_02 + validador_dia_03 +
			   validador_mes + validador_ano + validador_hora + validador_min +
			   validador_dia_atual + validador_mes_atual + validador_ano_atual +
			   validador_hora_atual + validador_min_atual;	// Deve dar 10 para ser válido

		if (soma == 10)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (opcao == 2)
	{
		soma = validador_dia_01 + validador_dia_02 + validador_dia_03 +
			   validador_mes + validador_ano + validador_dia_atual +
			   validador_mes_atual + validador_ano_atual;	// Deve dar 6 para ser válido

		if (soma == 6)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	// TESTA AS VALIDAÇÕES
	/*
		printf(" Soma: %d\n\n", soma);
		printf(" Validador dia: %d\n", validador_dia_01 + validador_dia_02 + validador_dia_03);
		printf(" Validador mes: %d\n", validador_mes);
		printf(" Validador ano: %d\n", validador_ano);
		printf(" Validador hora: %d\n", validador_hora);
		printf(" Validador min: %d\n\n", validador_min);
		printf(" Validador dia atual: %d\n", validador_dia_atual);
		printf(" Validador mes atual: %d\n", validador_mes_atual);
		printf(" Validador ano atual: %d\n", validador_ano_atual);
		printf(" Validador hora atual: %d\n", validador_hora_atual);
		printf(" Validador min atual: %d\n\n", validador_min_atual);
	*/
}

int valida_cpf(char * cpf) // Valida se o CPF é valido
{
	int i, j, digito1 = 0, digito2 = 0;
	if(strlen(cpf) != 11)
		return 0;
	else if((strcmp(cpf, "00000000000") == 0) || (strcmp(cpf, "11111111111") == 0) || (strcmp(cpf, "22222222222") == 0) ||
			(strcmp(cpf, "33333333333") == 0) || (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) ||
			(strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) || (strcmp(cpf, "88888888888") == 0) ||
			(strcmp(cpf, "99999999999") == 0))
		return 0; ///se o CPF tiver todos os números iguais ele é inválido.
	else
	{
		///digito 1---------------------------------------------------
		for(i = 0, j = 10; i < strlen(cpf) - 2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
			digito1 += (cpf[i] - 48) * j;
		digito1 %= 11;
		if(digito1 < 2)
			digito1 = 0;
		else
			digito1 = 11 - digito1;
		if((cpf[9] - 48) != digito1)
			return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
		else
			///digito 2--------------------------------------------------
		{
			for(i = 0, j = 11; i < strlen(cpf) - 1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
				digito2 += (cpf[i] - 48) * j;
			digito2 %= 11;
			if(digito2 < 2)
				digito2 = 0;
			else
				digito2 = 11 - digito2;
			if((cpf[10] - 48) != digito2)
				return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
		}
	}
	return 1;
}

int valida_nome(char * nome) // Valida se o Nome é valido
{
	int a;
	int finalizador = 0;

	for (a = 0; a < tam_nome; a++)
	{
		if (nome[a] <= 96 || nome[a] >= 123) // Se for um carac sem ser letra
		{
			if ((nome[a] <= 64 || nome[a] >= 91) && nome[a] != 32 && nome[a] != NULL)
			{
				printf(" Nao sao aceitos caracteres especiais nos nomes\n\n");
				return 0;
			}
		}
		if (nome[a] == 32 && finalizador == 0)
		{
			if (nome[a + 1] == 32 || nome[a + 1] == NULL) // Se tiver 2 espaços entre o nome
			{
				printf(" Espacos demais entre os nomes\n\n");
				return 0;
			}
			if (a < 2) // Se tiver menos de 3 letras
			{
				printf(" Primeiro nome com menos de 3 letras\n\n");
				return 0;
			}
			finalizador = 1;
		}
		if (nome[a] == NULL && finalizador == 0)	// Se n tiver sobrenome
		{
			printf(" Preciso de pelo menos 1 sobrenome\n\n");
			return 0;
		}
	}
	if (nome[tam_nome - 1] != NULL)
	{
		printf(" Nome grande demais, utilize abreviacoes se necessario\n\n");
	}
	return 1;
}

void clear() // Limpa o Terminal
{
#if defined(linux) || defined(unix) || defined(APPLE)
	system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
	system("cls");
#endif
}

int limitacoes()
{
	system("cls");
	printf("===============================================================\n\n");
	printf("                    QUALIDADES DO SOFTWARE \n\n\n");
	printf("------------------------- QUALIDADES --------------------------\n\n");
	printf(" [1] Salva um backup da ultima exclusao de voo\n");
	printf(" [2] Valida todas as entradas, inclusive o nome\n");
	printf(" [3] Os usuarios uma vez cadastrados permanecerao salvos\n\n");
	printf("---------------------------------------------------------------\n\n");
	printf(" Obs: Para acessar o backup o usuario deve acessar manualmente\n");
	printf(" o backup localizado na mesma pasta em que o software esta.\n\n");
	system("pause");
}
