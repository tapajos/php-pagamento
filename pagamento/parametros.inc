<?php
include '../funcoes/funcoesDeData.inc';

$dataAtualFormatoNormal = getDataAtualFormatada();

//DADOS GLOBAIS
define ("ARQUIVO_SUCESSO","telasDeRetorno/sucesso_visa.inc");
define ("ARQUIVO_FRACASSO","telasDeRetorno/fracasso_visa.inc");
define ("ARQUIVO_SUCESSO_REDECARD","telasDeRetorno/sucesso_redecard.inc");
define ("ARQUIVO_FRACASSO_REDECARD","telasDeRetorno/fracasso_redecard.inc");

//DADOS DA LOJA
define ("FAX","+55 (21) 2221-7635");
define ("LIB","lib/");

//DADOS BOLETO
define ("URL_BOLETO", "http://comercio.locaweb.com.br/boleto/boleto.comp");
define ("AGENCIA_BOLETO", "31186");
define ("CONTA_BOLETO", "camaecafe-bb");
define ("BANCO_BOLETO", "bb");
define ("CODIGO_CEDENTE_BOLETO", "170011");
define ("INSTRUCAO1", "0");
define ("INSTRUCAO2", "0");
define ("INSTRUCAO3", "0");
define ("INSTRUCAO4", "0");
define ("INSTRUCAO5", "0");
define ("CODIGO_BB","0367148");
define ("carteira","18/019");
define ("DiasdeVencimento", "7");

//DADOS VISANET
define ("URL_VISA_CARTAO", "https://comercio.locaweb.com.br/visavbv/dados_visa_vbv.asp");
define ("URL_CHECA_RETORNO_VISA_CARTAO","http://comercio.locaweb.com.br/visavbv/dados_visa_vbv.asp");
define ("URLRETORNO_CARTAO_VISA","http://www.camaecafe.com.br/recibo_visanet.php");
define ("MERCHID", "camaecafe");
define ("AUTHENTTYPE", "");
define ("FREE", "");
define ("AFILIACAO_LOJA","1014124511");
define ("TIPO_PAGAMENTO_VISTA_VISA","10");
define ("TIPO_PAGAMENTO_PRAZO_JUROS_LOJISTA_VISA","20");
define ("TIPO_PAGAMENTO_PRAZO_JUROS_EMISSOR_VISA","30");
define ("POSICAODADOSVISANET","0");


//DADOS REDECARD
define ("URL_MASTERCARD_CARTAO", "https://cartao.locaweb.com.br/comercio.comp");
define ("MEIO_PAGAMENTO_SEGURO_REDECARD", "REDECARD");
define ("METODO_REDECARD","SAFENET");
define ("LOJA_REDECARD","camaecafe");
define ("FILIACAO_REDECARD","19392850");
define ("TRANSACAO_REDECARD","203");
define ("TRANSACAO_CUPOM_REDECARD","201");
define ("BANDEIRA_REDECARD_CREDICARD","CREDICARD");
define ("BANDEIRA_REDECARD_DINERS","DINERS");
define ("POPUP_REDECARD","0");
define ("URLBACK_REDECARD","http://www.camaecafe.com.br/recibo_redecard.php");
define ("URLCUPOM_REDECARD","https://ecommerce.redecard.com.br/pos_virtual/cupom.asp");
define ("AVS_REDECARD","");
define ("TRANSORIGEM_AVISTA_REDECARD","04");
define ("TRANSORIGEM_COM_JUROS_REDECARD","06");
define ("TRANSORIGEM_SEM_JUROS_REDECARD","08");
define ("URL_CONFIRMACAO_ENVIO_REDECARD","");

?>
