/* Build a parser 'Adjective' to recognize descriptions */
mpc_parser_t* Adjective = mpc_or(4,
				mpc_sym("wow"), mpc_sym("many"),
				mpc_sym("so"), mpc_sym("such")
				);

/* Build a parser 'Noun' to recognize things */
mpc_parser_t* Noun = mpc_or(5,
				mpc_sym("lisp"), mpc_sym("language"),
				mpc_sym("book"), mpc_sym("build"),
				mpc_sym("c")
				);

/* Build a parser 'Phrase' to recognize statements */
mpc_parser_t* Phrase = mpc_and(2, mpcf_strfold,
				Adjective, Noun, free);

/* Build a parser 'Doge' to recognize doges */
mpc_parser_t* Doge = mpc_many(mpcf_strfold, Phrase);

/* Load AST from output */
mpc_ast_t* a = r.output;
printf("Tag: %s\n", a->tag);
printf("Contents: %s\n", a->contents);
printf("Number of children: %i\n", a->children_num);

/* Get First Child */
mpc_ast_t* c0 = a->children[0];
printf("First Child Tag: %s\n", c0->contents);
printf("First Child Number of children: %i\n", c0->children_num);


