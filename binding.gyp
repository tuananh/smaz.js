{
  'targets': [{
    'target_name': 'smaz.js',
    'sources': [
      'src/smaz.js.cc'
    ],
    'dependencies': [
      'src/smaz.gyp:smaz'
    ],
    'include_dirs': [
      '<!(node -e "require(\'nan\')")'
    ],
    'cflags_cc': [
      '-fexceptions',
      '-Wall',
      '-march=native',
      '-Ofast',
      '-flto'
    ],
    'xcode_settings': {
      'OTHER_CPLUSPLUSFLAGS': [
        '-fexceptions',
        '-Wall',
        '-march=native',
        '-Ofast'
      ],

    }
  }]
}