/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AStar.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <aorji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:55:42 by aorji             #+#    #+#             */
/*   Updated: 2019/10/17 22:38:30 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_ASTAR_HPP
#define I_ASTAR_HPP

#include "HeuristicFunction.hpp"

class AStar
{
public:
    explicit AStar(Puzzle *init_state, eHeuristic heuristic);
    bool run();
    void print_solution();
    ~AStar();

private:
    bool _solved;
    std::priority_queue<Puzzle *, std::vector<Puzzle *>, ComparePuzzle> _open_list;
    std::set<Puzzle *, ComparePuzzleSet> _closed_list;
    Puzzle *_curr_state;
    Puzzle *_goal_state;
    std::map<Puzzle *, Puzzle *> _from;
    std::vector<Puzzle *> _available_states;
    HeuristicFunction *_heuristic;
    size_t _complexity_in_time;
    size_t _complexity_in_size;

    AStar();
    AStar(AStar const &);
    AStar & operator=(AStar const &);

    void compute_top_state(void);
    
    void add_to_open(Puzzle *p);
    void close_top_state();
    bool in_closed(Puzzle *p);
    void remove_from_closed(Puzzle *p);
    Puzzle *is_under_review(Puzzle *p);
    void add_to_available(Puzzle *p);
    std::vector<Puzzle *> available_states(void);
    Puzzle *create_puzzle(int *data, int size, int pos);
    
    bool is_goal_state();
    void set_goal_state();
    
    void set_score(Puzzle *p, float g);
    inline float distance()
    {
        return 0.3;
    }

    HeuristicFunction *choose_heuristic(eHeuristic heuristic);
};

#endif
