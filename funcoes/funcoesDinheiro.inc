<?php

/*
 * calculaValorSemVirgulas -> Retorna o valor sem pontos nem virgulas.
 * Exemplo: entrada 100,00 saida 10000 
 */
 
function calculaValorSemVirgulas($valor) {
  $valor = str_replace(".", "", $valor);
  $valor = str_replace(",", "", $valor);
  return $valor;
}

/*
 * calculaValorComReais -> Concatena o R$ antes 
 *  
 */
 	
function calculaValorComReais($valor) {
	$valor = "R\$".$valor;
	return $valor;
}

function getCotacaoDolar(){
	if(!$fp=fopen("http://www.bc.gov.br/htms/infecon/taxas/taxas.htm" ,"r" )) {
		echo "Erro ao abrir a página de cotação" ;
	}else {
		$conteudo = '';
		while(!feof($fp)) { // leia o conteúdo da página
			$conteudo .= fgets($fp,1024);
	    }
	    fclose($fp);
	
		/*
		  Na expressão regular abaixo pego os dois números que tem o seguinte formato:
		  9,9999 (ex.: 2,8182)
		  O primeiro número é a taxa de compra e o segunda, taxa de venda .*([0-9]/[0-9]/[0-9]{4}
		*/
		eregi("([0-9],[0-9]{3}).*([0-9],[0-9]{3})",$conteudo, $saida);
		list($lixo,$taxaCompra,$taxaVenda) = $saida;
		
		eregi("[0-9]./[0-9]./[0-9]{4}",$conteudo, $data);
		list($data) = $data;
		$taxaCompra = str_replace(",", ".", $taxaCompra);	
		return $taxaCompra;
		//return $taxaVenda;
	} 

}
function converteReal2Dolar($real) {
        $dolar = $real/getCotacaodolar();
        $dolar = round ($dolar,2);
        $dolar = number_format($dolar,2,'.',"");
        return $dolar;

}
?>
