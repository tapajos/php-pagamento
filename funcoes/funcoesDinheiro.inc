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

?>
