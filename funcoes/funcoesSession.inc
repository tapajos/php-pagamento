<?php

function variaveisViaSession() {

foreach ($_SESSION as $campo => $valor) {
    $$campo = $valor;
}
	
}

?>
