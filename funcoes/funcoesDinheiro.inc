<?php

function calculaValorSemVirgulas($valor) {
  $valor = str_replace(".", "", $valor);
  $valor = str_replace(",", "", $valor);
  return $valor;
}
	
function calculaValorComReais($valor) {
	$valor = "R\$".$valor;
	return $valor;
}

?>
