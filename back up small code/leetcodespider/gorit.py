from bs4 import BeautifulSoup
import os
soup=BeautifulSoup(open('algorithms.html'),'html.parser')
tables=soup.body.find_all('table')
table1=tables[1]
#output=open('data_table.txt','w')
#output.write(table1.pretiffy())
#output.close()
thead1=table1.thead
tbody1=table1.tbody
output=open('data_tbody.txt','w')
output.write(tbody1.prettify())
output.close()
trs=tbody1.find_all('tr')
output=open('table.md','w')
for tr in trs:
	tds=tr.find_all('td')
	output.write('|'+tds[1].string)
	output.write('|'+'['+tds[2].a.string+']'+'('+'https://leetcode.com'+tds[2].a['href']+')')
	output.write('|.cpp|'+'\n')
	os.makedirs('./leetcode/'+tds[1].string+' '+tds[2].a.string)
output.close()
	
