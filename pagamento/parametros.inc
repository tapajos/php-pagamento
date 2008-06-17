<?php
include '../funcoes/funcoesDeData.inc';

$dataAtualFormatoNormal = getDataAtualFormatada();

//DADOS GLOBAIS
define ("ARQUIVO_SUCESSO","telasDeRetorno/sucesso_visa.inc");
define ("ARQUIVO_FRACASSO","telasDeRetorno/fracasso_visa.inc");
define ("ARQUIVO_SUCESSO_REDECARD","telasDeRetorno/sucesso_redecard.inc");
define ("ARQUIVO_FRACASSO_REDECARD","telasDeRetorno/fracasso_redecard.inc");

//DADOS DA LOJA
define ("FAX","");
define ("LIB","lib/");

//DADOS BOLETO
define ("URL_BOLETO", "");
define ("AGENCIA_BOLETO", "");
define ("CONTA_BOLETO", "");
define ("BANCO_BOLETO", "");
define ("CODIGO_CEDENTE_BOLETO", "");
define ("INSTRUCAO1", "0");
define ("INSTRUCAO2", "0");
define ("INSTRUCAO3", "0");
define ("INSTRUCAO4", "0");
define ("INSTRUCAO5", "0");
define ("CODIGO_BB","");
define ("carteira","");
define ("DiasdeVencimento", "");

//DADOS VISANET
define ("URL_VISA_CARTAO", "");
define ("URL_CHECA_RETORNO_VISA_CARTAO","");
define ("URLRETORNO_CARTAO_VISA","");
define ("MERCHID", "");
define ("AUTHENTTYPE", "");
define ("FREE", "");
define ("AFILIACAO_LOJA","");
define ("TIPO_PAGAMENTO_VISTA_VISA","10");
define ("TIPO_PAGAMENTO_PRAZO_JUROS_LOJISTA_VISA","20");
define ("TIPO_PAGAMENTO_PRAZO_JUROS_EMISSOR_VISA","30");
define ("POSICAODADOSVISANET","0");


//DADOS REDECARD
define ("URL_MASTERCARD_CARTAO", "");
define ("MEIO_PAGAMENTO_SEGURO_REDECARD", "REDECARD");
define ("METODO_REDECARD","SAFENET");
define ("LOJA_REDECARD","");
define ("FILIACAO_REDECARD","");
define ("TRANSACAO_REDECARD","203");
define ("TRANSACAO_CUPOM_REDECARD","201");
define ("BANDEIRA_REDECARD_CREDICARD","CREDICARD");
define ("BANDEIRA_REDECARD_DINERS","DINERS");
define ("POPUP_REDECARD","0");
define ("URLBACK_REDECARD","");
define ("URLCUPOM_REDECARD","");
define ("AVS_REDECARD","");
define ("TRANSORIGEM_AVISTA_REDECARD","04");
define ("TRANSORIGEM_COM_JUROS_REDECARD","06");
define ("TRANSORIGEM_SEM_JUROS_REDECARD","08");
define ("URL_CONFIRMACAO_ENVIO_REDECARD","http://ecommerce.redecard.com.br/pos_virtual/confirma.asp");

?>
