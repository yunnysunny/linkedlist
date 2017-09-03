{
  'targets': [
    {
      # have to specify 'liblib' here since gyp will remove the first one :\
      'target_name': 'mysql_bindings',
      'sources': [
        'src/mysql_bindings.cc',
        'src/mysql_bindings_connection.cc',
        'src/mysql_bindings_result.cc',
        'src/mysql_bindings_statement.cc',
      ],
      "include_dirs" : [
        '<!(node -e "require(\'nan\')")'
      ]
    }
  ]
}