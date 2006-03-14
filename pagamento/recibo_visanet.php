<?
include 'parametros.inc';
include '../funcoes/funcoesPostEgets.inc';
include LIB.'funcoesVisa.inc';

variaveisViaGet();
variaveisViaPost();

// Monta a url para captura do Retorno
$filename=URL_CHECA_RETORNO_VISA_CARTAO."?tid=$tid&PosicaoDadosVisanet=1&URLRetornoVisa=".URLRETORNO_CARTAO_VISA."&tiporesp=file";

// Efetua a captura do lr e recupera o retorno
$file = file($filename); 
$retorna = $file[0]; 
$arrLinhas = explode("<br>", $retorna);
$i = 0; 
foreach ($arrLinhas AS $line) { 
list($variavel, $valor) = explode(':', ($line)); 
$variavel = strtolower(trim($variavel)); 
$$variavel = trim($valor);
$i ++; 
}


if (in_array($lr,$RETORNO_APROVADO)){
	$msg = MSG_RETORNO_APROVADO;
	include ARQUIVO_SUCESSO;	
}
else {	
	if (in_array($lr,$RETORNO_NAO_APROVADO))	$msg = MSG_RETORNO_NAO_APROVADO;
	else if (in_array($lr,$RETORNO_NAO_APROVADO_CONTATAR_CARTAO)) $msg = MSG_RETORNO_NAO_APROVADO_CONTATAR_CARTAO;
	else if (in_array($lr,$RETORNO_NAO_APROVADO_LIMITE)) $msg = MSG_RETORNO_NAO_APROVADO_LIMITE;
	else if (in_array($lr,$RETORNO_NAO_APROVADO_REFAZER_TRANSACAO)) $msg = MSG_RETORNO_NAO_APROVADO_REFAZER_TRANSACAO;
	else if (in_array($lr,$RETORNO_NAO_APROVADO_SISTEMA_INDISPONIVEL)) $msg = MSG_RETORNO_NAO_APROVADO_SISTEMA_INDISPONIVEL;
	else $msg = MSG_RETORNO_NAO_APROVADO_PADRAO;
	include ARQUIVO_FRACASSO;
}
?>