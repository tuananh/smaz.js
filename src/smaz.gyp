{
  'targets': [{
    'target_name': 'smaz',
    'type': 'static_library',
    'sources': [
      'smaz/smaz.c'
    ],
    'cflags': [
      '-std=c99',
      '-fexceptions',
      '-Wall',
      '-march=native',
      '-Ofast'
    ],
    'xcode_settings': {
      'OTHER_CFLAGS': [
        '-std=c99',
        '-fexceptions',
        '-Wall',
        '-march=native',
        '-Ofast'
      ]
    }
  }]
}