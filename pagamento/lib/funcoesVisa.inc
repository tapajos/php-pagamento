<?php

/*
 * Conjunto de valores de possiveis retornos do VISA
 */
$RETORNO_APROVADO = array(0,11);
$RETORNO_NAO_APROVADO = array(1,2,3,12,21,22,25,28,54,57,62,63,76,77,80,93);
$RETORNO_NAO_APROVADO_CONTATAR_CARTAO = array(4,5,7,14,41,43,51,52,53,65);
$RETORNO_NAO_APROVADO_REFAZER_TRANSACAO = array(6,19,55,81,82,83,86);
$RETORNO_NAO_APROVADO_LIMITE = array(61);
$RETORNO_NAO_APROVADO_SISTEMA_INDISPONIVEL = array(15,91,98,99);

/*
 * Conjunto das mensagens que vamos exibir de acordo com o retorno. 
 */
define ("MSG_RETORNO_APROVADO", "");
define ("MSG_RETORNO_NAO_APROVADO", "");
define ("MSG_RETORNO_NAO_APROVADO_CONTATAR_CARTAO", "");
define ("MSG_RETORNO_NAO_APROVADO_REFAZER_TRANSACAO", "");
define ("MSG_RETORNO_NAO_APROVADO_LIMITE", "");
define ("MSG_RETORNO_NAO_APROVADO_SISTEMA_INDISPONIVEL", "");
define ("MSG_RETORNO_NAO_APROVADO_PADRAO", "");

/*
 * GerarTidVisa gera o numero de transação para o VISA de acordo com as regras deles
 */
function GerarTidVisa ($shopid,$tipoPagamento,$numParcelas) {

    if(strlen($shopid) != 10) {
        geraErroParaDebugApenas("Tamanho do shopid deve ser 10 dígitos");
	}
	
	if(is_numeric($shopid) != 1) {
        geraErroParaDebugApenas("Shopid deve ser numérico");
	}

    if(strlen($tipoPagamento.$numParcelas) != 4) {
        geraErroParaDebugApenas("Tamanho do código de pagamento deve ser 4 dígitos.");
        
	}

    //Número da Maquineta
    $shopid_formatado = substr($shopid, 4, 5);

    //Hora Minuto Segundo e Décimo de Segundo
    $hhmmssd = date("His").substr(sprintf("%0.1f",microtime()),-1);

    //Obter Data Juliana
    $datajuliana = sprintf("%03d",(date("z")+1));

	//Último dígito do ano
    $dig_ano = substr(date("y"), 1, 1);
    
    return $shopid_formatado.$dig_ano.$datajuliana.$hhmmssd.$tipoPagamento.$numParcelas;
    
  }
/*
 * geraErroParaDebugApenas mostra erros que só podem acontecer se a gente configurar alguma coisa errada
 * no sistema de pagamento ou na integração com o site!
 */
function geraErroParaDebugApenas($erro_msg) {
	echo $erro_msg;
	exit;
}
/*
 * paga_visa faz o post dos dados para o sistema VISANET e depois vai para a URL de retorno !
 */
function paga_visa($url, $valor, $tipoPagamento,$orderId,$order,$merchId,
					$authenttype,$free,$afiliacaoLoja,$numParcelas,$PosicaoDadosVisanet){
    
	$price = calculaValorSemVirgulas($valor);
	$damount = calculaValorComReais($valor);
	$tid = GerarTidVisa($afiliacaoLoja,$tipoPagamento,$numParcelas);
	echo
	"<HTML> 
	<BODY onLoad='javascript:document.formPagamentoVisaCredito.submit();'>
	<form name='formPagamentoVisaCredito' method='POST' action='$url'>
   		<input type='hidden' name='price' value='$price'>
   		<input type='hidden' name='tid' value='$tid'>
   		<input type='hidden' name='orderid' value='$orderId'>
   		<input type='hidden' name='order' value='$order'>
   		<input type='hidden' name='merchid' value='$merchId'>
   		<input type='hidden' name='damount' value='$damount'>
   		<input type='hidden' name='authenttype' value='$authenttype'>
   		<input type='hidden' name='free' value='$free'>
   		<input type='hidden' name='PosicaoDadosVisanet' value='$PosicaoDadosVisanet'>
	</form>
	</BODY>
	</html>";
	
}
?>
