### prefer iris drivers
GALLIUMDRIVERS:append:x86 = ",iris"
GALLIUMDRIVERS:append:x86-64 = ",iris"

SRC_URI:append = " file://0001-Allow-enable-DRI-without-DRI-drivers.patch \
                   file://0001-Workaround_push_constant_corruption_on_context_switch.patch"
# mesa driver override settings
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"
FILES:mesa-megadriver:append = " ${sysconfdir}"
SRC_URI:append:x86-64:class-target = " \
                      file://mesa_driver.sh \
"
RDEPENDS:${PN}-megadriver:append:class-target:x86-64 = " dmidecode"

# mesa driver settings (should be in mesa-megadriver)
do_install:append:class-target:x86-64() {
        install -m 755 -d ${D}${sysconfdir}/profile.d
        install -Dm0644 ${WORKDIR}/mesa_driver.sh ${D}${sysconfdir}/profile.d/mesa_driver.sh
}
###

#fix comma issue
python(){
    dri = d.getVar('DRIDRIVERS')
    d.setVar('DRIDRIVERS', dri.strip(','))

    vulk = d.getVar('VULKAN_DRIVERS')
    d.setVar('VULKAN_DRIVERS', vulk.strip(','))
}
