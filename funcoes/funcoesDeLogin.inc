<?php
 
 function validaLoginTosco($login,$senha) {
 	
   if ($login=="tapajos" && $senha =="senha") $_SESSION['logado'] = true;
 }
 
 function verificaLogado () {
 	
 	if (isset($_SESSION['logado'])) return true;
 	else return false;
}
 
?>
