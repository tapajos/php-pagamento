<?php
/*
 * variaveisViaSession -> Cria todas as variaveis via Session
 */
function variaveisViaSession() {

foreach ($_SESSION as $campo => $valor) {
    $$campo = $valor;
}
	
}

?>
