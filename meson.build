project(
  'glines', 'c',
  version: '1.0.0',
  meson_version: '>= 0.59.0',
  license: 'GPL3+',
  default_options: [
    'c_std=c17',
    'warning_level=2',
    'buildtype=debug'
  ])

app_name      = meson.project_name()
app_id        = 'sk.jkalmar.glines'
app_version   = meson.project_version()
app_is_debug  = get_option('buildtype').startswith('debug')

app_prefix    = get_option('prefix')
app_srcdir    = meson.project_source_root()
app_builddir  = meson.project_build_root()
app_bindir    = join_paths(app_prefix, get_option('bindir'))
app_localedir = join_paths(app_prefix, get_option('localedir'))
app_datadir   = join_paths(app_prefix, get_option('datadir'))
app_schemadir = join_paths(app_datadir, 'glib-2.0', 'schemas')
app_po_dir    = join_paths(app_srcdir, 'po')
top_inc       = include_directories('.')
src_inc       = include_directories('src')

gnome = import('gnome')
i18n  = import('i18n')
cc    = meson.get_compiler('c')


conf = configuration_data()
conf.set('NDEBUG', (not app_is_debug))
conf.set('G_DISABLE_ASSERT', (not app_is_debug))
conf.set('G_DISABLE_CAST_CHECKS', (not app_is_debug))
conf.set_quoted('GETTEXT_APP', app_name)
conf.set_quoted('APP_NAME', app_name)
conf.set_quoted('APP_ID', app_id)
conf.set_quoted('APP_LOCALE_DIR', app_localedir)

configure_file(
  output: 'config.h',
  configuration: conf,
)

common_flags = [
  '-D_FORTIFY_SOURCE=2',
  '-DG_LOG_USE_STRUCTURED',
]

add_global_arguments(common_flags, language: 'c')
c_args = cc.get_supported_arguments(
  ['-fasynchronous-unwind-tables',
   '-fno-strict-aliasing',
   '-Wall',
   '-Wextra',
   '-pipe',
  ])

add_project_arguments(c_args, language: 'c')

app_dep = [
  dependency('glib-2.0', version: '>= 2.62.0'),
  dependency('gtk4'),
  dependency('libadwaita-1'),
]

subdir('src')

gnome.post_install(
  glib_compile_schemas: true,
  gtk_update_icon_cache: true,
  update_desktop_database: true,
)

# Toolchain
summary('Target', target_machine.system(), section: 'Toolchain')
summary('Target arch', target_machine.cpu(), section: 'Toolchain')
summary('Compiler', cc.get_id(), section: 'Toolchain')
summary('Version', cc.version(), section: 'Toolchain')
summary('Linker', cc.get_linker_id(), section: 'Toolchain')

# Build
summary('Build type', get_option('buildtype'), section: 'Build')
summary('Tests', get_option('tests'), section: 'Build')
summary('Documentation', get_option('gtk_doc'), section: 'Build')
summary('Translations', get_option('po'), section: 'Build')

# Directories
summary('app_prefix', app_prefix, section: 'Directories')
summary('app_srcdir', app_srcdir, section: 'Directories')
summary('app_builddir', app_builddir, section: 'Directories')
summary('app_bindir', app_bindir, section: 'Directories')
summary('app_localedir', app_localedir, section: 'Directories')
summary('app_datadir', app_datadir, section: 'Directories')
summary('app_schemadir', app_schemadir, section: 'Directories')
summary('app_po_dir', app_po_dir, section: 'Directories')


