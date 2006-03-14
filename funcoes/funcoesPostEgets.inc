<?php

function variaveisViaPost() {

foreach ($_POST as $campo => $valor) {
    $$campo = $valor;
}
	
}

function variaveisViaGet() {

foreach ($_GET as $campo => $valor) {
    $$campo = $valor;
}
	
}

?>
