<?php
session_start();
include 'parametros.inc';
include '../funcoes/funcoesSession.inc';
include LIB.'funcoesRedecard.inc';

variaveisViaSession();

if (isset($_GET['NR_CARTAO'])) $nrCartao = $_GET['NR_CARTAO'];
if (isset($_GET['ORIGEM_BIN'])) $origemBin = $_GET['ORIGEM_BIN'];
if (isset($_GET['NUMAUTOR'])) $numAutor = $_GET['NUMAUTOR'];
if (isset($_GET['NUMCV'])) $numCV = $_GET['NUMCV'];
if (isset($_GET['NUMAUTENT'])) $numAutent = $_GET['NUMAUTENT'];
if (isset($_GET['NUMSQN'])) $numSQN = $_GET['NUMSQN'];
if (isset($_GET['CODRET'])) $codRet = $_GET['CODRET'];
if (isset($_GET['MSGRET'])) $msgRet = $_GET['MSGRET'];

if (!isset($data)) $data = date(Y).date(m).date(d);

if ($parcelas != "00") {
	if ($juros=="1") $transOrig = TRANSORIGEM_COM_JUROS_REDECARD;
	else if ($juros=="0") $transOrig = TRANSORIGEM_SEM_JUROS_REDECARD;
}
else $transOrig = TRANSORIGEM_AVISTA_REDECARD;	

if ($codRet != "" && $codRet!= "0"){
   $status = $codRet;
   $autent = $msgRet;
} else {
   $status = 0;
   $autent = $numAutent;
}

/*
 * Confirma transação com a Redecard
 */
 
if ($status == 0) {
    $valores = "DATA=" . $data;
    $valores = $valores . "&TRANSACAO=".TRANSACAO_REDECARD;
    $valores = $valores . "&TRANSORIG=" . $transOrig;
    $valores = $valores . "&PARCELAS=" . $parcelas;
    $valores = $valores . "&FILIACAO=" . FILIACAO_REDECARD;
	$valores = $valores . "&DISTRIBUIDOR="; // este campo deve ser nulo
    $valores = $valores . "&TOTAL=" . $valor;
    $valores = $valores . "&PEDIDO=" . $pedido;
    $valores = $valores . "&NUMAUTOR=" . $numAutor;
    $valores = $valores . "&NUMCV=" . $numCV;
    $valores = $valores . "&NUMSQN=" . $numSQN;
    
	// contacta RedeCard e confirma transação
	$filename=URL_CONFIRMACAO_ENVIO_REDECARD."?" . $valores;

	$file = file($filename); 
	$retorna = $file[0]; 
	$arrLinhas = explode("&", $retorna);
	$i = 0; 
	foreach ($arrLinhas AS $line) { 
	   list($variavel, $valor) = explode('=', ($line)); 
	   $variavel = trim($variavel); 
	   $$variavel = $valor ; 
	   $i ++; 
	}
	$status = $codRet;
	if ($status > 1) {
	   $autent = $msgRet;
	}
}	

// **************************** Em caso de falha na transação ***************
if ($status > 1){
	include ARQUIVO_FRACASSO_REDECARD;

}
else if ($status == 1){
	// ************** Em caso da transação já ter sido confirmada ***************
	echo "Transação já confirmada.";
}
else {
	include ARQUIVO_SUCESSO_REDECARD;
}
?>
