AM_DEFAULT_SOURCE_EXT = .cpp
AM_CPPFLAGS = -iquote ${top_srcdir}

bin_PROGRAMS = \
	phosphor-psu-monitor

phosphor_psu_monitor_SOURCES = \
	main.cpp \
	psu_manager.cpp

phosphor_psu_monitor_CXXFLAGS = \
	$(SDBUSPLUS_CFLAGS) \
	$(PHOSPHOR_LOGGING_CFLAGS) \
	${PHOSPHOR_DBUS_INTERFACES_CFLAGS}

phosphor_psu_monitor_LDADD = \
	${top_builddir}/libpower.la \
	$(SDBUSPLUS_LIBS) \
	$(PHOSPHOR_LOGGING_LIBS) \
	${PHOSPHOR_DBUS_INTERFACES_LIBS}
