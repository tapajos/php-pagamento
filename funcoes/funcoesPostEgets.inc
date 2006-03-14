<?php
/*
 * variaveisViaPost -> Cria todas as variaveis via post
 */
 
function variaveisViaPost() {

foreach ($_POST as $campo => $valor) {
    $$campo = $valor;
}
	
}

/*
 * variaveisViaGet -> Cria todas as variaveis via get
 */

function variaveisViaGet() {

foreach ($_GET as $campo => $valor) {
    $$campo = $valor;
}
	
}

?>
