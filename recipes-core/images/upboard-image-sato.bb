DESCRIPTION = "Linux image for UP family boards based on core-image-sato"

LICENSE = "GPL-2.0-only"

require recipes-sato/images/core-image-sato.bb
require ${@bb.utils.contains('UP_SECURE_BOOT', '1', 'upboard-image-secureboot.inc', '', d)}
require upboard-image-sato.inc

