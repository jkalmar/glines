src = []

# Generate version.h file in src directory and fill the version from project
conf_version = configuration_data()
conf_version.set_quoted('APP_VERSION', app_version)

configure_file(
  output: 'version.h',
  configuration: conf_version,
)

# every build (ninja) this will regenerate the buildinfo.h with commit hash
commmit_dep = vcs_tag(command : ['git', 'rev-parse', 'HEAD'],
            input : 'buildinfo.h.in',
            output : 'buildinfo.h',
            replace_string : 'VCS_HASH')

src += [
  'main.c',
  'about.c',
  'gamewindow.c'
]

executable(
  'glines',
  src,
  install: true,
  install_dir : '~/glines',
  win_subsystem: 'windows',
  include_directories: top_inc,
  dependencies: app_dep,
)
