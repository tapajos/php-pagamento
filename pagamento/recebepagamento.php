<?php
include 'parametros.inc';
include '../funcoes/funcoesDinheiro.inc';
include '../funcoes/funcoesPostEgets.inc';
include LIB.'funcoesVisa.inc';
include LIB.'funcoesRedecard.inc';
include LIB.'funcoesBoleto.inc';

variaveisViaPost();
variaveisViaGet();

$juros = 0;
if ($juros=="0")
	$tipoPagamento = TIPO_PAGAMENTO_VISTA_VISA;
else if ($juros=="1"){
	$tipoPagamento = TIPO_PAGAMENTO_PRAZO_JUROS_LOJISTA_VISA;
}
else if ($juros=="2"){
	$tipoPagamento = TIPO_PAGAMENTO_PRAZO_JUROS_EMISSOR_VISA;
}

if ($forma_pagamento=='cartao') {
	if ($cartao=='MASTERCARD') {
		paga_redecard(URL_MASTERCARD_CARTAO, $valor, MEIO_PAGAMENTO_SEGURO_REDECARD,
			METODO_REDECARD,LOJA_REDECARD,BANDEIRA_REDECARD_CREDICARD,$numParcelas,$pedido,
			$juros,POPUP_REDECARD,URLBACK_REDECARD,AVS_REDECARD);
	}
	else if ($cartao =='DINERS') {
		paga_redecard(URL_MASTERCARD_CARTAO, $valor, MEIO_PAGAMENTO_SEGURO_REDECARD,
			METODO_REDECARD,LOJA_REDECARD,BANDEIRA_REDECARD_DINERS,$numParcelas,$pedido,
			$juros,POPUP_REDECARD,URLBACK_REDECARD,AVS_REDECARD);;
	}
	else if ($cartao=='VISA') {
		paga_visa(URL_VISA_CARTAO, $valor, $tipoPagamento ,$pedido,$pedidoDescricao,MERCHID,
				AUTHENTTYPE,FREE,AFILIACAO_LOJA,$numParcelas, POSICAODADOSVISANET);
	}
	else if ($cartao == 'AMERICAN') {
		paga_american();
	}
}
else if ($forma_pagamento=='transferencia') {
	if ($banco=='BRASIL'){
	}
}
else if($forma_pagamento=='boleto') {
	paga_boleto(URL_BOLETO, $valor, BANCO_BOLETO,AGENCIA_BOLETO,CODIGO_CEDENTE_BOLETO,
					$numdoc,CONTA_BOLETO,$sacado,$cgccpfsac,$datadoc,$vencimento,
					INSTRUCAO1,INSTRUCAO2,INSTRUCAO3,INSTRUCAO4,INSTRUCAO5,CODIGO_BB);
}
else if($forma_pagamento=='BRADESCO'){
}

?>
