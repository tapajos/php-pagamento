<?php
function paga_boleto($url, $valor, $banco,$agencia,$codigo_cedente,
					$numdoc,$conta,$sacado,$cgccpfsac,$datadoc,$vencto,
					$instr1,$instr2,$instr3,$instr4,$instr5,$codigo_bb){

	echo
	"<HTML>
	<BODY onLoad='javascript:document.formPagamentoBoleto.submit();'>
	<FORM NAME='formPagamentoBoleto' METHOD=POST ACTION=$url>
		<INPUT TYPE='hidden' NAME='valor' VALUE='$valor''>
		<INPUT TYPE='hidden' NAME='banco' VALUE='$banco'>
		<INPUT TYPE='hidden' NAME='agencia' VALUE='$agencia'>
		<INPUT TYPE='hidden' NAME='codigo_cedente' VALUE='$codigo_cedente'>
		<INPUT TYPE='hidden' NAME='numdoc' VALUE='$numdoc'>
		<INPUT TYPE='hidden' NAME='conta' VALUE='$conta'''>
		<INPUT TYPE='hidden' NAME='sacado' VALUE='$sacado'>
		<INPUT TYPE='hidden' NAME='cgccpfsac' VALUE='$cgccpfsac'>
		<INPUT TYPE='hidden' NAME='datado' VALUE='$datadoc'>
		<INPUT TYPE='hidden' NAME='vencto' VALUE='$vencto'>
		<INPUT TYPE='hidden' NAME='instr1' VALUE='$instr1'>
		<INPUT TYPE='hidden' NAME='instr2' VALUE='$instr2'>
		<INPUT TYPE='hidden' NAME='instr3' VALUE='$instr3'>
		<INPUT TYPE='hidden' NAME='instr4' VALUE='$instr4'>
		<INPUT TYPE='hidden' NAME='instr5' VALUE='$instr5'>
		<INPUT TYPE='hidden' NAME='codigo_bb' VALUE='$codigo_bb'>
	</FORM>
	</BODY>
	
	</html>";
	
}

?>
