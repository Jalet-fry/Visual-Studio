#include "header.h"

//for exam
int count_depth(Tree* node, int depth) {
    if(!node){
        return 0;
    }
    depth++;
    if(node->left && node->right){
        return max(count_depth(node->left, depth), count_depth(node->right, depth));
    }
    else if(node->left){
        return count_depth(node->left, depth);
    }
    else if(node->right){
        return count_depth(node->right, depth);
    }
    else{
        return depth;
    }
}
int find_diag(Tree* top) {
    if(!top){
        return -1;
    }
    return max(max(find_diag(top->left),  find_diag(top->right)), count_depth(top->left, 0) + count_depth(top->right, 0));
}
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

int max_independent_set(TreeNode* root) {
    if (!root) {
        return 0;
    }

    // Recursively compute the independent sets for children and grandchildren
    int exclude = max_independent_set(root->left) + max_independent_set(root->right);
    int include = 1; // Include the current node

    if (root->left) {
        include += max_independent_set(root->left->left) + max_independent_set(root->left->right);
    }
    if (root->right) {
        include += max_independent_set(root->right->left) + max_independent_set(root->right->right);
    }

    // Return the maximum of two sizes
    return (include > exclude) ? include : exclude;
}

void main() {
	char file_default[] = "C:\\Files_for_testing\\default_structure.bin",
		 file_user[] = "C:\\Files_for_testing\\user_structure_new.bin", 
		 file_tree_user[] = "C:\\Files_for_testing\\user_tree.bin",
		 choice, method = 1,
		 *welcome = "\n\tMenu:\n\t1) Create new model\n\t2) Find models by minimum configurations life cycle\n\t"
					"3) Delete by min_life cycle\n\t4) List of bodyType\n\t5) Print current model list\n\t"
					"6) Save current tree\n\t7) delete by ind\n\t8)Find by your life_span\n\t9) Exit\n\t"
					"10)Balance tree\n\t11)Change the way of printing\n\t"
					"12)Find models by minimum configurations life cyclet\n"
					"Select the option - ";
	Tree *user_tree = fill_our_tree(file_tree_user);
	while (1) {
		printf("our diag = %d\n", find_diag(user_tree));
        printf("our max_set = %d\n", max_independent_set(user_tree));
		switch (choice = correct(welcome)) {
		case 1:
			user_tree = add_Car_to_Tree(user_tree, create_car());
			break;
		case 2:
			find_model_by_life_cycle_configur_main(user_tree);
			break;
		case 3:
			tree_print_for_model_life_cycle(user_tree, 0);
			find_model_by_life_cycle_main(user_tree);
			user_tree = delete_model_with_min_lifecycle(user_tree);
			break;
		case 4:
			sort_in_tree_by_bodytypes(user_tree);
			break;
		case 5:
			tree_print_beautiful(user_tree, method);
			break;
		case 6:
			save_to_file(user_tree, file_tree_user, "wb", 0);
			break;
		case 7:
			user_tree = delete_by_your_index_main(user_tree);
			break;
		case 8:
			choice = correct("Enter your min_config_life_span:");
			find_models_with_your_conf_cycle(user_tree, choice);
			break;
		case 9:
			user_tree = free_tree(user_tree);
			tree_print_beautiful(user_tree, method);
			printf("\n------------------------\n");
			exit(0);
			break;
		case 10:
			user_tree = balance(user_tree);
			break;
		case 11:
			method = 1 - method;
			break;
		case 12:
			find_model_by_life_cycle_main(user_tree);
			break;
		default:
			printf("\n\nIncorrect input");
			break;
		}
	}
}
