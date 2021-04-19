import pandas as pd
import xlsxwriter
from sklearn.cluster import KMeans

vet = ['DF','ES','MG','RJ','SC','SP','AC','AL','AM','BA','CE','GO','MA','PA','PE','PI','RO','SE','TO','MS','RN','RS','AP','MT','PB','PR','RR']
dt= pd.read_csv('INFLUD-08-02-2021.csv', sep = ';')
ex = pd.read_excel('ocupacao.xlsx')
per = pd.read_excel('Militares.xlsx')
ida = pd.read_excel('idade.xlsx')
ind = pd.read_excel('tabelaIndigena.xls')
workbook = xlsxwriter.Workbook('demo.xlsx')
arquivo = open("dados_contaminados.txt", "w")
arquivo.write("Estado" + "	" + "Contaminados" + "	" + "Total" + "	" + "Taxa" + "	" + "Subgrupo" + "\n")
worksheet = workbook.add_worksheet()
worksheet.write('A1', 'Estado')
worksheet.write('B1', 'Contaminados')
worksheet.write('C1', 'Total')
worksheet.write('D1', 'Taxa')
worksheet.write('E1', 'Subgrupo')

j=2
##Povos indigenas
for i in range(len(vet)):
	print("Indigenas: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" & CS_RACA == 5 & CLASSI_FIN == 5')
	consultaEx = ind.query('Local == "'+vet[i]+'"')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Indígena'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Indígena'])*100))
	worksheet.write('E'+str(j)+' ', "Indigena")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Indígena']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Indígena'])*100),9)) + "	" + "Indigena" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Indígena'])
	j = j+1


# ~ ##Profissionais da saude
for i in range(len(vet)):
	print("Saude: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" &  (PAC_COCBO.str.startswith("223") | PAC_COCBO.str.startswith("515")) & CLASSI_FIN == 5')
	consultaEx = ex.query(' Estado == "'+vet[i]+'" & Ocupacao == "saude"')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Total'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100))
	worksheet.write('E'+str(j)+' ', "Saude")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Total']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100),9)) + "	" + "Saude" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Total'])
	j = j+1


##Pessoas com mais de 80 anos
for i in range(len(vet)):	
	print("Maior 80: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" & NU_IDADE_N >= 80 & CLASSI_FIN == 5')
	consultaEx = ida.query(' Estado == "'+vet[i]+'" & Idade == "80 anos ou mais" ')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Total'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100))
	worksheet.write('E'+str(j)+' ', "Maior80")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Total']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100),9)) + "	" + "Maior80" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Total'])
	j = j+1

	
##Pessoas entre 75 e 79 anos
for i in range(len(vet)):
	print("Maior 75: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" & NU_IDADE_N >= 75 & NU_IDADE_N <=79 & CLASSI_FIN == 5')
	consultaEx = ida.query(' Estado == "'+vet[i]+'" & Idade == "75 a 79 anos"')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Total'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100))
	worksheet.write('E'+str(j)+' ', "Maior75")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Total']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100),9)) + "	" + "Maior75" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Total'])
	j = j+1

	
##Pessoas entre 70 e 74 anos
for i in range(len(vet)):
	print("Maior 70: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" & NU_IDADE_N >= 70 & NU_IDADE_N <=74 & CLASSI_FIN == 5')
	consultaEx = ida.query(' Estado == "'+vet[i]+'" & Idade == "70 a 74 anos"')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Total'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100))
	worksheet.write('E'+str(j)+' ', "Maior70")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Total']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100),9)) + "	" + "Maior70" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Total'])
	j = j+1

	
##Pessoas entre 65 e 69 anos
for i in range(len(vet)):
	print("Maior 65: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" & NU_IDADE_N >= 65 & NU_IDADE_N <=69 & CLASSI_FIN == 5')
	consultaEx = ida.query(' Estado == "'+vet[i]+'" & Idade == "65 a 69 anos"')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Total'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100))
	worksheet.write('E'+str(j)+' ', "Maior65")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Total']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100),9)) + "	" + "Maior65" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Total'])
	j = j+1


##Pessoas entre 60 e 64 anos
for i in range(len(vet)):
	print("Maior 60: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" & NU_IDADE_N >= 60 & NU_IDADE_N <=64 & CLASSI_FIN == 5')
	consultaEx = ida.query(' Estado == "'+vet[i]+'" & Idade == "60 a 64 anos"')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Total'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100))
	worksheet.write('E'+str(j)+' ', "Maior60")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Total']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100),9)) + "	" + "Maior60" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Total'])
	j = j+1

		
##Profissionais do sistema de privacao de liberdade
for i in range(len(vet)):
	print("Agente penitenciario: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" &  PAC_COCBO == 517315 & CLASSI_FIN == 5')
	consultaEx = per.query(' Estado == "'+vet[i]+'" ')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Total'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100))
	worksheet.write('E'+str(j)+' ', "Agente")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Total']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100),9)) + "	" + "Agente" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Total'])
	j = j+1

	
##Trabalhadores da educacao do Ensino Basico
for i in range(len(vet)): 
	print("Ensino Basico: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" & (PAC_COCBO.str.startswith("231") | PAC_COCBO.str.startswith("232")) & CLASSI_FIN == 5')
	consultaEx = ex.query(' Estado == "'+vet[i]+'" & Ocupacao == "educacao"')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Total'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100))
	worksheet.write('E'+str(j)+' ', "EnsinoBasico")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Total']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100),9)) + "	" + "EnsinoBasico" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Total'])
	j = j+1

	
##Trabalhadores da educacao do  Ensino Superior
for i in range(len(vet)): 
	print("Ensino Superior: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" & PAC_COCBO.str.startswith("234") & CLASSI_FIN == 5')
	consultaEx = ex.query(' Estado == "'+vet[i]+'" & Ocupacao == "educacao"')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Total'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100))
	worksheet.write('E'+str(j)+' ', "EnsinoSuperior")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Total']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100),9)) + "	" + "EnsinoSuperior" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Total'])
	j = j+1


##Trabalhadores das forcas de seguranca e salvamento
for i in range(len(vet)): 
	print("Forcas de seguranca: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" & (PAC_COCBO.str.startswith("02") | PAC_COCBO.str.startswith("03") | PAC_COCBO.str.startswith("5172") ) & CLASSI_FIN == 5')
	consultaEx = per.query(' Estado == "'+vet[i]+'" ')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Total'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100))
	worksheet.write('E'+str(j)+' ', "ForcaSalv")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Total']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100),9)) + "	" + "ForcaSalv" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Total'])
	j = j+1


##Trabalhadores das forcas Armadas
for i in range(len(vet)): 
	print("Forcas armadas: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" & PAC_COCBO.str.startswith("01") & CLASSI_FIN == 5')
	consultaEx = per.query(' Estado == "'+vet[i]+'" ')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Total'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100))
	worksheet.write('E'+str(j)+' ', "ForcaArm")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Total']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100),9)) + "	" + "ForcaArm" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Total'])
	j = j+1


##Trabalhadores de transporte coletivo rodoviario de passageiros
for i in range(len(vet)): 
	print("Rodoviaria: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" & (PAC_COCBO.str.startswith("3423") | PAC_COCBO.str.startswith("7824") | PAC_COCBO.str.startswith("5112") | PAC_COCBO == 421110) & CLASSI_FIN == 5')
	consultaEx = ex.query(' Estado == "'+vet[i]+'" & Ocupacao == "transporte"')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Total'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100))
	worksheet.write('E'+str(j)+' ', "TransRod")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Total']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100),9)) + "	" + "TransRod" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Total'])
	j = j+1


##Trabalhadores de transporte metroviario e ferroviario
for i in range(len(vet)): 
	print("Metroviario: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" & (PAC_COCBO.str.startswith("7826") | PAC_COCBO.str.startswith("3424") | PAC_COCBO.str.startswith("511110") | PAC_COCBO.str.startswith("5112")) & CLASSI_FIN == 5')
	consultaEx = ex.query(' Estado == "'+vet[i]+'" & Ocupacao == "transporte"')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Total'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100))
	worksheet.write('E'+str(j)+' ', "TransMet")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Total']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100),9)) + "	" + "TransMet" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Total'])
	j = j+1

	
##Trabalhadores de  transporte aereo
for i in range(len(vet)): 
	print("Aereo: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" & (PAC_COCBO.str.startswith("3425") | PAC_COCBO.str.startswith("2153") | PAC_COCBO.str.startswith("3411") | PAC_COCBO.str.startswith("511105")) & CLASSI_FIN == 5')
	consultaEx = ex.query(' Estado == "'+vet[i]+'" & Ocupacao == "transporte"')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Total'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100))
	worksheet.write('E'+str(j)+' ', "TransAer")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Total']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100),9)) + "	" + "TransAer" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Total'])
	j = j+1


##Caminhoneiros
for i in range(len(vet)): 
	print("Caminhoneiros: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" & PAC_COCBO.str.startswith("7825") & CLASSI_FIN == 5')
	consultaEx = ex.query(' Estado == "'+vet[i]+'" & Ocupacao == "transporte"')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Total'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100))
	worksheet.write('E'+str(j)+' ', "Camin")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Total']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100),9)) + "	" + "Camin" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Total'])
	j = j+1


##Trabalhadores portuarios
for i in range(len(vet)): 
	print("Portuarios: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" & PAC_COCBO ==  "783230" & CLASSI_FIN == 5')
	consultaEx = ex.query(' Estado == "'+vet[i]+'" & Ocupacao == "transporte"')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Total'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100))
	worksheet.write('E'+str(j)+' ', "Port")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Total']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100),9)) + "	" + "Port" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Total'])
	j = j+1


##Trabalhadores industriais
for i in range(len(vet)): 
	print("Industrias: ", vet[i])
	worksheet.write('A'+str(j)+' ', vet[i])
	consulta = dt.query('SG_UF_NOT == "'+vet[i]+'" & (PAC_COCBO.str.startswith("76") | PAC_COCBO.str.startswith("81")) & CLASSI_FIN == 5')
	consultaEx = ex.query(' Estado == "'+vet[i]+'" & Ocupacao == "industria"')
	worksheet.write('B'+str(j)+' ', consulta.shape[0])
	worksheet.write('C'+str(j)+' ', consultaEx.iloc[0]['Total'])
	worksheet.write('D'+str(j)+' ', ((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100))
	worksheet.write('E'+str(j)+' ', "Indus")
	arquivo.write(vet[i] + "	" + str(consulta.shape[0]) + "	" + str(consultaEx.iloc[0]['Total']) + "	" + str(round(((consulta.shape[0]/consultaEx.iloc[0]['Total'])*100),9)) + "	" + "Indus" + "\n")
	print(consulta.shape[0])
	print(consultaEx.iloc[0]['Total'])
	j = j+1
arquivo.close()	
workbook.close()
