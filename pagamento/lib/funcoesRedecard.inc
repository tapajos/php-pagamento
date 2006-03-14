<?php

/*
 * paga_redecard faz o primeiro post passando os dados para o sistema da redecard.
 * Depois fica na URL de retorno esperando resposta !
 */
function paga_redecard($url, $valor, $meio_pagamento_seguro,$metodo,$loja,
					$bandeira,$parcelas,$pedido,$juros,$popup,$urlback,$avs){
						
						

	$valor2 = calculaValorSemVirgulas($valor);

	session_start();
 	$_SESSION['meio_pagamento_seguro']= $meio_pagamento_seguro;
   	$_SESSION['metodo'] = $metodo;
   	$_SESSION['loja'] =  $loja;
   	$_SESSION['valor'] =  $valor;
   	$_SESSION['BANDEIRA'] =  $bandeira;
   	$_SESSION['pedido'] =  $pedido;
   	$_SESSION['parcelas'] =  $parcelas;
   	$_SESSION['juros'] =  $juros;
   	$_SESSION['popup'] =  $popup;
   	$_SESSION['urlback'] =  $urlback;
   	$_SESSION['AVS'] =  $avs;

	echo
	"<HTML>
	<BODY onLoad='javascript:document.formPagamentoRedecardCredito.submit();'>	
	<form name='formPagamentoRedecardCredito' method='POST' action='$url'>
   		<input type='hidden' name='meio_pagamento_seguro' value='$meio_pagamento_seguro'>
   		<input type='hidden' name='metodo' value='$metodo'>
   		<input type='hidden' name='loja' value='$loja'>
   		<input type='hidden' name='valor' value='$valor2'>
   		<input type='hidden' name='BANDEIRA' value='$bandeira'>
   		<input type='hidden' name='pedido' value='$pedido'>
   		<input type='hidden' name='parcelas' value='$parcelas'>
   		<input type='hidden' name='juros' value='$juros'>
   		<input type='hidden' name='popup' value='$popup'>
   		<input type='hidden' name='urlback' value='$urlback'>
   		<input type='hidden' name='AVS' value='$avs'>
   	</form>
   	</BODY>
	</html>";
	
}
?>
